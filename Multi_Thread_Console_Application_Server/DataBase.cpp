#include "DataBase.h"
#include <algorithm>
// Constructor for the DataBase class, initializes the FilePath and calls initDataBase()
DataBase::DataBase(QObject *parent)
    : QObject{parent}, FilePath{"D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\Database\\LoginDB.json"}
{
    initDataBase(); // Initialize the database upon creation
}

// Function to initialize the database from the JSON file
void DataBase::initDataBase()
{
    jsonDataBase.clear(); // Clear the current database
    QFile file(FilePath); // Create a QFile object with the specified file path
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) // Open the file for reading
    {
        QByteArray byteArr = file.readAll(); // Read all data from the file
        QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr); // Parse the byte array to a QJsonDocument
        QJsonArray JsonArr = jsonDoc.array(); // Convert QJsonDocument to QJsonArray
        for (int i = 0; i < JsonArr.size(); i++) // Iterate through the JSON array
        {
            QJsonObject jsonObj = JsonArr[i].toObject(); // Convert each element to QJsonObject
            jsonDataBase << jsonObj; // Append the JSON object to the database
        }
        file.close(); // Close the file
    }
    else
    {
        qDebug() << "Can't Open the database file" << Qt::endl; // Debug message if the file can't be opened
    }
}

// Function to verify user credentials
QString DataBase::verifyCredentials(const QString& username, const QString& password)
{
    initDataBase(); // Ensure the database is initialized
    for (const auto& user : jsonDataBase) // Iterate through each user record
    {
        if (user["Username"].toString() == username && user["Password"].toString() == password) // Check credentials
        {
            return user["Autority"].toString(); // Return user authority if credentials are valid
        }
    }
    return QString(); // Return an empty string if credentials are invalid
}

// Function to get the account number for a given username
QString DataBase::getAccountNumber(const QString& username)
{
    initDataBase(); // Ensure the database is initialized
    for (const auto& user : jsonDataBase) // Iterate through each user record
    {
        if (user["Username"].toString() == username) // Check username
        {
            return user["AccountNumber"].toString(); // Return account number if username matches
        }
    }
    return QString(); // Return an empty string if username is not found
}

// Function to get the account balance for a given account number
int DataBase::getAccountBalance(const QString &accountNumber)
{
    initDataBase(); // Ensure the database is initialized
    for (const auto& record : jsonDataBase) { // Iterate through each account record
        if (record["AccountNumber"].toString() == accountNumber) { // Check account number
            return record["Balance"].toInt(); // Return balance if account number matches
        }
    }
    return 0; // Return 0 if account number is not found
}

// Function to get the transaction history for a given account number
QJsonArray DataBase::getTransactionHistory(const QString &accountNumber, int count)
{
    initDataBase(); // Ensure the database is initialized

    QJsonArray transactions; // Create an empty QJsonArray to hold the resulting transactions

    // Iterate through each account record in the JSON database
    for (const auto& record : jsonDataBase) {
        // Check if the current record's account number matches the requested one
        if (record["AccountNumber"].toString() == accountNumber) {
            QJsonArray transactionArray = record["Transactions"].toArray(); // Get the array of transactions for the account
            QVector<QJsonObject> transactionVector; // Create a QVector to hold transactions for sorting

            // Loop through the transactionArray from end to beginning
            for (int i = transactionArray.size() - 1; i >= 0; --i) {
                QJsonObject transaction = transactionArray[i].toObject(); // Get each transaction as a QJsonObject
                transactionVector.append(transaction); // Add each transaction to the QVector
            }

            // Sort the QVector of transactions by date in descending order
            std::sort(transactionVector.begin(), transactionVector.end(), [](const QJsonObject &a, const QJsonObject &b) {
                return QDate::fromString(a["date"].toString(), "dd-MM-yyyy") > QDate::fromString(b["date"].toString(), "dd-MM-yyyy");
            });

            // Add up to 'count' transactions to the result array
            for (int i = 0; i < count && i < transactionVector.size(); ++i) {
                transactions.append(transactionVector[i]);
            }
            break; // Exit the loop once the account has been found and processed
        }
    }

    return transactions; // Return the array containing the transactions
}



// Function to get the account email for a given account number
QString DataBase::getAccountEmail(const QString &accountNumber)
{
    initDataBase();  // Ensure the database is initialized

    for (const auto& record : jsonDataBase) { // Iterate through each account record
        if (record["AccountNumber"].toString() == accountNumber) { // Check account number
            return record["Email"].toString(); // Return email if account number matches
        }
    }
    return QString(); // Return an empty string if account number is not found
}

// Function to make a transaction on a given account
bool DataBase::makeTransaction(const QString &accountNumber, int transactionAmount)
{
    initDataBase(); // Ensure the database is initialized
    for (auto& record : jsonDataBase) { // Iterate through each account record
        if (record["AccountNumber"].toString() == accountNumber) { // Check account number
            int currentBalance = record["Balance"].toInt(); // Get current balance
            if (transactionAmount < 0 && (currentBalance < qAbs(transactionAmount))) {
                return false; // Insufficient funds for withdrawal
            }
            record["Balance"] = currentBalance + transactionAmount; // Update balance

            QJsonObject transaction; // Create a new transaction object
            transaction["date"] = QDate::currentDate().toString("dd-MM-yyyy"); // Set transaction date
            transaction["Amount"] = transactionAmount; // Set transaction amount
            transaction["type"] = transactionAmount >= 0 ? "deposit" : "withdrawal"; // Set transaction type

            QJsonArray transactions = record["Transactions"].toArray(); // Get current transactions
            transactions.append(transaction); // Add new transaction
            record["Transactions"] = transactions; // Update transactions

            saveDataBase(); // Save changes to the database
            return true; // Transaction successful
        }
    }
    return false; // Account number not found
}

// Function to transfer amount from one account to another
bool DataBase::transferAmount(const QString &fromAccountNumber, const QString &toAccountNumber, int transferAmount)
{
    qInfo() << "in database" << Qt::endl; // Debug message
    initDataBase(); // Ensure the database is initialized

    QJsonObject fromRecord; // Object to hold the 'from' account record
    QJsonObject toRecord; // Object to hold the 'to' account record
    int fromRecordIndex = -1; // Index of 'from' account in jsonDataBase
    int toRecordIndex = -1; // Index of 'to' account in jsonDataBase

    for (int i = 0; i < jsonDataBase.size(); ++i) { // Iterate through each account record
        QJsonObject record = jsonDataBase[i];
        if (record["AccountNumber"].toString() == fromAccountNumber) { // Check 'from' account number
            fromRecord = record;
            fromRecordIndex = i;
        }
        if (record["AccountNumber"].toString() == toAccountNumber) { // Check 'to' account number
            toRecord = record;
            toRecordIndex = i;
        }
    }

    if (fromRecordIndex == -1 || toRecordIndex == -1) {
        return false; // One or both account numbers not found
    }

    int fromBalance = fromRecord["Balance"].toInt(); // Get balance of 'from' account
    if (transferAmount <= 0 || fromBalance < transferAmount) {
        return false; // Invalid transfer amount or insufficient funds
    }

    int toBalance = toRecord["Balance"].toInt(); // Get balance of 'to' account
    fromRecord["Balance"] = fromBalance - transferAmount; // Deduct amount from 'from' account
    toRecord["Balance"] = toBalance + transferAmount; // Add amount to 'to' account

    QJsonObject transactionFrom; // Create a new transaction for 'from' account
    transactionFrom["date"] = QDate::currentDate().toString("dd-MM-yyyy"); // Set transaction date
    transactionFrom["Amount"] = -transferAmount; // Set transaction amount (negative for transfer out)
    transactionFrom["type"] = "transfer_to_" + toAccountNumber; // Set transaction type

    QJsonArray fromTransactions = fromRecord["Transactions"].toArray(); // Get current transactions of 'from' account
    fromTransactions.append(transactionFrom); // Add new transaction
    fromRecord["Transactions"] = fromTransactions; // Update transactions

    QJsonObject transactionTo; // Create a new transaction for 'to' account
    transactionTo["date"] = QDate::currentDate().toString("dd-MM-yyyy"); // Set transaction date
    transactionTo["Amount"] = transferAmount; // Set transaction amount (positive for transfer in)
    transactionTo["type"] = "transfer_from_" + fromAccountNumber; // Set transaction type

    QJsonArray toTransactions = toRecord["Transactions"].toArray(); // Get current transactions of 'to' account
    toTransactions.append(transactionTo); // Add new transaction
    toRecord["Transactions"] = toTransactions; // Update transactions

    // Update the records in the jsonDataBase array
    jsonDataBase[fromRecordIndex] = fromRecord;
    jsonDataBase[toRecordIndex] = toRecord;

    saveDataBase(); // Save changes to the database
    return true; // Transfer successful
}

// Function to view the entire bank database
QJsonArray DataBase::viewBankDatabase()
{
    initDataBase(); // Ensure the database is initialized

    QJsonArray databaseArray; // Create an empty QJsonArray to hold the database
    for (const auto& record : jsonDataBase) { // Iterate through each account record
        QJsonObject accountDetails; // Create a QJsonObject for account details
        accountDetails["Username"] = record["Username"].toString(); // Set username
        accountDetails["AccountNumber"] = record["AccountNumber"].toString(); // Set account number
        accountDetails["Autority"] = record["Autority"].toString(); // Set authority
        accountDetails["Balance"] = record["Balance"].toInt(); // Set balance
        accountDetails["Email"] = record["Email"].toString(); // Set email
        accountDetails["FullName"] = record["FullName"].toString(); // Set full name
        accountDetails["Age"] = record["Age"].toInt(); // Set age
        accountDetails["Password"] = record["Password"].toString(); // Set password

        QJsonArray transactions = record["Transactions"].toArray(); // Get transactions
        accountDetails["Transactions"] = transactions; // Add transactions to account details

        databaseArray.append(accountDetails); // Add account details to the database array
    }

    return databaseArray; // Return the database array
}


// Function to create a new user and add them to the database
bool DataBase::createNewUser(const QJsonObject &userData)
{
    initDataBase(); // Ensure the database is initialized

    QString newUsername = userData["Username"].toString(); // Get new username
    QString newAccountNumber = userData["AccountNumber"].toString(); // Get new account number

    // Check if the username or account number already exists
    for (const QJsonObject &record : jsonDataBase) {
        if (record["Username"].toString() == newUsername || record["AccountNumber"].toString() == newAccountNumber) {
            return false; // Username or account number already exists
        }
    }

    // Create a new QJsonObject with fields in the desired order
    QJsonObject newUser;
    newUser["Username"] = userData["Username"];
    newUser["AccountNumber"] = generateRandomAccountNumber(9);
    newUser["Age"] = userData["Age"];
    newUser["Autority"] = "user";
    newUser["Balance"] = userData["Balance"];
    newUser["Email"] = userData["Email"];
    newUser["FullName"] = userData["FullName"]; 
    newUser["Password"] = userData["Password"];
    newUser["Transactions"] = userData["Transactions"];

    // Add the new user to the database
    jsonDataBase.append(newUser);

    // Save the updated database
    saveDataBase();

    return true; // User creation successful
}



// Function to delete a user by their account number
bool DataBase::deleteUser(const QString &accountNumber)
{
    initDataBase(); // Ensure the database is initialized

    // Find the user with the given account number and remove them
    for (int i = 0; i < jsonDataBase.size(); ++i) {
        if (jsonDataBase[i]["AccountNumber"].toString() == accountNumber) {
            jsonDataBase.removeAt(i); // Remove user from the database
            saveDataBase(); // Save the updated database
            return true; // User deleted successfully
        }
    }
    return false; // Account number not found
}

// Function to update user information
bool DataBase::updateUser(const QString &accountNumber, const QJsonObject &newData)
{
    initDataBase(); // Ensure the database is initialized

    // Find the user with the given account number and update their data
    for (auto &record : jsonDataBase) {
        if (record["AccountNumber"].toString() == accountNumber) {
            for (auto it = newData.begin(); it != newData.end(); ++it) {
                record[it.key()] = it.value(); // Update record with new data
            }
            saveDataBase(); // Save the updated database
            return true; // User updated successfully
        }
    }
    return false; // Account number not found
}

// Function to  generate random account numbers
QString DataBase::generateRandomAccountNumber(int length)
{
    QString accountNumber;
    QRandomGenerator randomGenerator;

    for (int i = 0; i < length; ++i) {
        int digit = randomGenerator.bounded(10); // Generate a random digit (0-9)
        accountNumber.append(QString::number(digit));
    }

    return accountNumber;
}





// Function to save the current state of the database to a file
void DataBase::saveDataBase()
{
    QJsonArray jsonArr; // Create a QJsonArray to hold all records
    for (const auto& record : jsonDataBase) {
        jsonArr.append(record); // Add each record to the JSON array
    }

    QFile file(FilePath); // Create a QFile object with the specified file path
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) { // Open file for writing
        file.write(QJsonDocument(jsonArr).toJson()); // Write JSON array to the file
        file.close(); // Close the file
    } else {
        qDebug() << "Can't Open the database file" << Qt::endl; // Debug message if the file can't be opened
    }
}

