#include "mainwindow.h"  // Include the MainWindow class header
#include "ui_mainwindow.h"  // Include the UI header for MainWindow

// Enumeration for GUI windows to manage different pages
enum GUI_Windows
{
    LoginPage = 0,  // Index for the login page
    UserPage,  // Index for the user page
    ViewTransactionPage,  // Index for the view transaction page
    MakeTransactionPage,  // Index for the make transaction page
    MakeTransferAmountPage,  // Index for the make transfer amount page
    AdminPage,  // Index for the admin page
    AdminViewTransactionPage,  // Index for the admin view transaction page
    AdminViewBankDatabasePage,  // Index for the admin view bank database page
    AdminCreateUserPage,  // Index for the admin create user page
    AdminUpdateUserPage  // Index for the admin update user page
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)  // Call the base class constructor
    , ui(new Ui::MainWindow)  // Initialize the UI pointer
{
    ui->setupUi(this);  // Set up the UI components

    // Connect client signals to the corresponding slots
    connect(&client, &MyClient::Connection, this, &MainWindow::onConnectionDevice);
    connect(&client, &MyClient::Disconnected, this, &MainWindow::onDisconnectedDevice);
    connect(&client, &MyClient::ErrorOccurred, this, &MainWindow::onErrorOccurredDevice);
    connect(&client, &MyClient::StateChanged, this, &MainWindow::onStateChangedDevice);
    connect(&client, &MyClient::ReadyRead, this, &MainWindow::onReadyReadDevice);

    ui->Login_page->setCurrentIndex(LoginPage);  // Set the initial page to LoginPage
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);  // Set the password field to hide input characters


    QStringList options;  // Create a list to hold transaction types
    options << "None" << "Deposit" << "Withdrow";  // Add transaction types to the list
    ui->comboBox_UserTransactionType->addItems(options);  // Populate the combo box with transaction types

    Images_init();  // Initialize images
}

MainWindow::~MainWindow()
{
    delete ui;  // Clean up the UI pointer
}

void MainWindow::Images_init()
{
    QPixmap pix("D:\\ITIDA_Scholarship\\Final project\\images.ico");  // Load an image from the file path
    ui->pic1_bankLogo->setPixmap(pix);  // Set the image to a label for the bank logo

    QPixmap pix2("D:\\ITIDA_Scholarship\\Final project\\OIP.png");  // Load another image from the file path
    ui->pic2_userame->setPixmap(pix2);  // Set the image to a label for the username

    QPixmap pix3("D:\\ITIDA_Scholarship\\Final project\\password.png");  // Load another image from the file path
    ui->pic3_password->setPixmap(pix3);  // Set the image to a label for the password
}

/******************************** MainWindow slots *******************************************/

// Slot for handling the connection event
void MainWindow::onConnectionDevice()
{
    qInfo() << "Client has connected to the server....\n";  // Log that the client has connected
}

// Slot for handling the disconnection event
void MainWindow::onDisconnectedDevice()
{
    qInfo() << "Client has disconnected from the server....\n";  // Log that the client has disconnected
}

// Slot for handling socket errors
void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();  // Get the meta-enum for socket errors
    qInfo() << meta.valueToKey(socketError) << "\n";  // Log the error type
}

// Slot for handling state changes in the socket
void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();  // Get the meta-enum for socket states
    qInfo() << meta.valueToKey(socketState) << "\n";  // Log the new state
}


void MainWindow::onReadyReadDevice(const QJsonObject &response)
{
    // Check if the status in the response is "success"
    if (response["status"].toString() == "success")
    {
        handleLoginResponse(response);  // Handle login response
    }
    // Check if the status in the response is "failed"
    else if (response["status"].toString() == "failed")
    {
        // Show a critical error message if login failed
        QMessageBox::critical(nullptr, "Error", "Login failed: Invalid username or password.");
    }
    // Check if the status in the response is "success_GetAccountNumber"
    else if (response["status"].toString() == "success_GetAccountNumber")
    {
        handleAccountNumberResponse(response);  // Handle account number response
    }
    // Check if the status in the response is "account_balance_response"
    else if (response["status"].toString() == "account_balance_response")
    {
        handleAccountBalancerResponse(response);  // Handle account balance response
    }
    // Check if the status in the response is "transaction_history_response"
    else if (response["status"].toString() == "transaction_history_response")
    {
        displayTransactionHistory(response);  // Display transaction history
    }
    // Check if the status in the response is "transaction_amount_response"
    else if (response["status"].toString() == "transaction_amount_response")
    {

        // Check if the transaction result is "Transaction successful"
        if (response["transaction_Result"].toString() == "Transaction successful")
        {
            // Show an information message for successful transaction
            QMessageBox::information(nullptr, "Transaction Response", "Transaction successful.");
        }
        else
        {
            // Show a critical message if the transaction failed
            QMessageBox::critical(nullptr, "Transaction Response", "Transaction failed. No sufficient balance");
        }

    }
    // Check if the status in the response is "transfer_response"
    else if (response["status"].toString() == "transfer_response")
    {
        // Check if the transfer result is "Transfer successful"
        if (response["transsfer_Result"].toString() == "Transfer successful")
        {
            // Show an information message for successful transfer
            QMessageBox::information(nullptr, "Transfer Response", "Transfer successful.");
        }
        else
        {
            // Show a critical message if the transfer failed
            QMessageBox::critical(nullptr, "Transfer Response", "Transfer failed. Please check account number or transfer amount and try again.");
        }
    }
    // Check if the status in the response is "ViewBankDatabase_response"
    else if (response["status"].toString() == "ViewBankDatabase_response")
    {
        displayDatabaseData(response);  // Display database data
    }
    // Check if the status in the response is "CreateUser_response"
    else if (response["status"].toString() == "CreateUser_response")
    {
        // Check if the new user result is "Create new user successful"
        if (response["NewUser_Result"].toString() == "Create new user successful")
            QMessageBox::information(nullptr, "New User Response", "Create new user successful.");  // Show success message
        else
            QMessageBox::critical(nullptr, "New User Response", "Create new user failed.");  // Show failure message
    }
    // Check if the status in the response is "DeleteUser_response"
    else if (response["status"].toString() == "DeleteUser_response")
    {
        // Check if the delete user result is "Delete user successful"
        if (response["DeleteUser_Result"].toString() == "Delete user successful")
            QMessageBox::information(nullptr, "Delete user Response", "Delete user successful.");  // Show success message
        else
            QMessageBox::critical(nullptr, "Delete User Response", "Delete user failed. This account number doesn't exist. Try again");  // Show failure message
    }
    // Check if the status in the response is "UpdateUser_response"
    else if (response["status"].toString() == "UpdateUser_response")
    {
        // Check if the update user result is "Update user successful"
        if (response["UpdateUser_Result"].toString() == "Update user successful")
            QMessageBox::information(nullptr, "Update user Response", "Update user successful.");  // Show success message
        else
            QMessageBox::critical(nullptr, "Update User Response", "Update user failed. Try again");  // Show failure message
    }
    else
    {
        // Log an invalid response and show a critical error message
        qInfo() << "invalid response" << Qt::endl;
        QMessageBox::critical(nullptr, "Error", "Something wrong happened with your request. Try to start again");
    }
}



/******************************** Responses *******************************************/

void MainWindow::handleLoginResponse(const QJsonObject& response)
{
    QString authority = response["authority"].toString();  // Retrieve the user's authority level
    this->client_authority = authority;  // Store the user's authority level
    this->client_accountNumber = response["account_number"].toString();  // Store the user's account number

    // Check if the authority level is "user"
    if (authority == "user")
    {
        ui->Login_page->setCurrentIndex(UserPage);  // Switch to the user page
        ui->Label_textUser->setText("Welcome " + this->client_username);  // Display a welcome message with the username
    }
    // Check if the authority level is "admin"
    else if (authority == "admin")
    {
        ui->Login_page->setCurrentIndex(AdminPage);  // Switch to the admin page
    }
}

void MainWindow::handleAccountNumberResponse(const QJsonObject& response)
{
    QString accountNumber = response["account_number"].toString();  // Retrieve the account number from the response

    // Check if the account number is empty
    if (accountNumber.isEmpty())
        QMessageBox::critical(nullptr, "Error", "This username doesn't exist");  // Show an error message if the username doesn't exist
    else
        QMessageBox::information(nullptr, "Information", "This is your account number message=>" + accountNumber);  // Show the account number
}

void MainWindow::handleAccountBalancerResponse(const QJsonObject& response)
{
    int balance = response["balance"].toInt();  // Retrieve the account balance from the response
    QString str_balance = QString::number(balance);  // Convert the balance to a string

    // Check if the balance is less than or equal to 0
    if (balance <= 0)
        QMessageBox::critical(nullptr, "Error", "This account number doesn't exist");  // Show an error message if the account number doesn't exist
    else
        QMessageBox::information(nullptr, "Account Balance", "The account balance is ===>" + str_balance);  // Show the account balance
}

void MainWindow::displayTransactionHistory(const QJsonObject& response)
{
    QJsonArray transactions = response["transactions"].toArray();  // Retrieve the transactions array from the response

    // Check if the user authority is "user"
    if (this->client_authority == "user")
    {
        ui->transactionHistoryTable->setRowCount(transactions.size());  // Set the row count for the user transaction history table
        ui->transactionHistoryTable->setColumnCount(3);  // Set the column count
        ui->transactionHistoryTable->setHorizontalHeaderLabels(QStringList() << "Date" << "Amount" << "type");  // Set the column headers

        // Iterate over each transaction
        for (int i = 0; i < transactions.size(); ++i) {
            QJsonObject transaction = transactions[i].toObject();  // Get the transaction object
            ui->transactionHistoryTable->setItem(i, 0, new QTableWidgetItem(transaction["date"].toString()));  // Set the date
            ui->transactionHistoryTable->setItem(i, 1, new QTableWidgetItem(QString::number(transaction["Amount"].toInt())));  // Set the amount
            ui->transactionHistoryTable->setItem(i, 2, new QTableWidgetItem(transaction["type"].toString()));  // Set the type
        }
    }
    else
    {
        // If the user authority is not "user", assume it is "admin"
        ui->Admin_transactionHistoryTable->setRowCount(transactions.size());  // Set the row count for the admin transaction history table
        ui->Admin_transactionHistoryTable->setColumnCount(3);  // Set the column count
        ui->Admin_transactionHistoryTable->setHorizontalHeaderLabels(QStringList() << "Date" << "Amount" << "type");  // Set the column headers

        // Iterate over each transaction
        for (int i = 0; i < transactions.size(); ++i) {
            QJsonObject transaction = transactions[i].toObject();  // Get the transaction object
            ui->Admin_transactionHistoryTable->setItem(i, 0, new QTableWidgetItem(transaction["date"].toString()));  // Set the date
            ui->Admin_transactionHistoryTable->setItem(i, 1, new QTableWidgetItem(QString::number(transaction["Amount"].toInt())));  // Set the amount
            ui->Admin_transactionHistoryTable->setItem(i, 2, new QTableWidgetItem(transaction["type"].toString()));  // Set the type
        }
    }
}

void MainWindow::displayDatabaseData(const QJsonObject &jsonObject)
{
    QJsonArray jsonArray = jsonObject["data"].toArray(); // Assuming 'data' key holds the array of user records

    // Set up the table widget for displaying the database data
    ui->TW_AdminViewBankDatabase->clear();  // Clear any existing data in the table widget
    ui->TW_AdminViewBankDatabase->setRowCount(0);  // Reset the row count to zero
    ui->TW_AdminViewBankDatabase->setColumnCount(8); // Set the column count to 8 for user data

    QStringList headers;  // Create a list of column headers
    headers << "Username" << "AccountNumber" << "Autority" << "Balance" << "Email" << "FullName" << "Age" << "Password";
    ui->TW_AdminViewBankDatabase->setHorizontalHeaderLabels(headers);  // Set the column headers for the table widget

    // Add rows for each record from the JSON array
    for (const QJsonValue &value : jsonArray) {  // Iterate over each item in the JSON array
        QJsonObject record = value.toObject();  // Convert the JSON value to a JSON object
        int currentRow = ui->TW_AdminViewBankDatabase->rowCount();  // Get the current row count
        ui->TW_AdminViewBankDatabase->insertRow(currentRow);  // Insert a new row at the end of the table widget

        // Set the data for each column in the current row
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 0, new QTableWidgetItem(record["Username"].toString()));  // Username
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 1, new QTableWidgetItem(record["AccountNumber"].toString()));  // Account Number
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 2, new QTableWidgetItem(record["Autority"].toString()));  // Authority
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 3, new QTableWidgetItem(QString::number(record["Balance"].toInt())));  // Balance
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 4, new QTableWidgetItem(record["Email"].toString()));  // Email
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 5, new QTableWidgetItem(record["FullName"].toString()));  // Full Name
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 6, new QTableWidgetItem(QString::number(record["Age"].toInt())));  // Age
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 7, new QTableWidgetItem(record["Password"].toString()));  // Password
    }

    ui->Login_page->setCurrentIndex(AdminViewBankDatabasePage);  // Switch to the admin view bank database page
}



/******************************** Slots of Ui design  *****************************************/
//function to get your local ip
QString MainWindow::getLocalIpAddress()
{
    // Define the name of the wireless interface to match
    QString wirelessInterfaceName = "Wi-Fi";  // This should match your wireless adapter name

    // Variable to store the IP address
    QString ipAddress;

    // Get a list of all network interfaces on the system
    QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();

    // Iterate through each network interface
    for (const QNetworkInterface &interface : allInterfaces)
    {
        // Check if the current interface matches the specified wireless interface name
        if (interface.humanReadableName() == wirelessInterfaceName)
        {
            // Get all address entries for the matching network interface
            QList<QNetworkAddressEntry> allAddresses = interface.addressEntries();

            // Iterate through each address entry
            for (const QNetworkAddressEntry &entry : allAddresses)
            {
                // Check if the address entry is an IPv4 address
                if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol)
                {
                    // Set the IP address to the first found IPv4 address
                    ipAddress = entry.ip().toString();
                }
            }
        }
    }

    // If no IPv4 address was found, fall back to the localhost address
    if (ipAddress.isEmpty())
    {
        // Set the IP address to localhost
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

        // Log the fallback IP address for debugging
        qInfo() << "Local" << ipAddress << Qt::endl;
    }

    // Return the IP address
    return ipAddress;
}



void MainWindow::on_PB_Login_clicked()
{
    qInfo() << "in the func";  // Log that the login function is called
    QString ip;
    QString username = ui->lineEdit_username->text();  // Get the username from the input field
    QString password = ui->lineEdit_password->text();  // Get the password from the input field
    this->client_username = username;  // Store the username for future reference
    if (username.isEmpty() || password.isEmpty()) {  // Check if either username or password is empty
        QMessageBox::warning(this, "Login", "Please enter both username and password.");  // Show warning message

        return;  // Exit the function
    }

    if (username.contains(' ') || password.contains(' ')) {  // Check if username or password contains spaces
        QMessageBox::warning(this, "Login", "Invalid username or password. Please enter both username and password without spaces.");  // Show warning message

        return;  // Exit the function
    }

    if(ui->leIP->isEnabled())
    {
        ip = ui->leIP->text();

    }
    else
    {
        ip= getLocalIpAddress(); //get your ip
        ui->leIP->setText(ip); //show it on Line Edit
    }
    if (ip.isEmpty()) {  // Check if ip is empty
        QMessageBox::warning(this, "Login", "Please enter IP.");  // Show warning message

        return;  // Exit the function
    }



   // QString ip= getLocalIpAddress();
    qInfo()<<"ip"<<ip<<Qt::endl;
    qint32 port = SERVER_PORT;  // Define the server port
    client.ConnectToDevice(ip, port);  // Connect to the server

    QJsonObject loginRequest;  // Create a JSON object for the login request
    loginRequest["type"] = "login";  // Set the type of request
    loginRequest["username"] = username;  // Set the username in the request
    loginRequest["password"] = password;  // Set the password in the request

    // Convert QJsonObject to QJsonDocument
    QJsonDocument jsonDoc(loginRequest);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the login request to the server
}

void MainWindow::on_UserGetAccountNo_PB_clicked()
{
    QString username = this->client_username;  // Retrieve the stored username
    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "GetAccountNumber";  // Set the type of request
    request["username"] = username;  // Set the username in the request
    qInfo() << "username=>" << username << Qt::endl;  // Log the username

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_UserAccountBalance_PB_clicked()
{
    bool ok;  // Variable to check if input dialog was accepted
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"),
                                                  tr("Enter your account number:"), QLineEdit::Normal,
                                                  "", &ok);  // Show input dialog to get account number
    if (!ok || accountNumber.isEmpty()) {  // Check if input was not accepted or is empty
        QMessageBox::critical(this, "Error", "Account number is required");  // Show critical error message
        return;  // Exit the function
    }
    if (accountNumber.contains(' ')) {  // Check if account number contains spaces
        QMessageBox::critical(this, "Error", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "ViewAccountBalance";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_UserViewTransaction_PB_2_clicked()
{
    ui->Login_page->setCurrentIndex(ViewTransactionPage);  // Switch to the view transaction page
}

void MainWindow::on_UserShowTransactin_PB_clicked()
{
    QString accountNumber = ui->lineEdit_UserAccountNumber->text();  // Get the account number from the input field

    int count = ui->spinBox_UserCount->value();  // Get the count from the spin box

    if (accountNumber.isEmpty()) {  // Check if account number is empty
        QMessageBox::warning(this, "View Transaction", "Please enter account number.");  // Show warning message

        return;  // Exit the function
    }
    if (accountNumber.contains(' ')) {  // Check if account number contains spaces
        QMessageBox::critical(this, "Error", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }
    if (accountNumber != this->client_accountNumber) {  // Check if account number does not match the stored account number
        QMessageBox::critical(this, "View Transaction", "Wrong account number. Please try again");  // Show critical error message
        return;  // Exit the function
    }

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "ViewTransactionHistory";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request
    request["count"] = count;  // Set the count in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_UserLogout_PB_clicked()
{
    ui->Login_page->setCurrentIndex(LoginPage);  // Switch to the login page
}

void MainWindow::on_Back_PB_clicked()
{
    ui->Login_page->setCurrentIndex(UserPage);  // Switch to the user page
}

void MainWindow::on_UserMakeTransaction_PB_clicked()
{
    ui->Login_page->setCurrentIndex(MakeTransactionPage);  // Switch to the make transaction page
}

void MainWindow::on_UserTransferAmount_PB_clicked()
{
    ui->Login_page->setCurrentIndex(MakeTransferAmountPage);  // Switch to the make transfer amount page
}

void MainWindow::on_UserConfirmTransaction_PB_clicked()
{
    QString accountNumber = ui->lineEdit_UserAccountNumber_Transaction->text();  // Get the account number from the input field
    int transactionAmount = ui->lineEdit_UserTransactionAmount->text().toInt();  // Get the transaction amount from the input field
    QString transactionType = ui->comboBox_UserTransactionType->currentText();  // Get the transaction type from the combo box

    if (accountNumber.isEmpty()) {  // Check if account number is empty
        QMessageBox::warning(this, "Make Transaction Request", "Please enter account number.");  // Show warning message

        return;  // Exit the function
    }
    if (accountNumber != this->client_accountNumber) {  // Check if account number does not match the stored account number
        QMessageBox::critical(this, "Make Transaction Request", "Wrong account number. Please try again");  // Show critical error message
        return;  // Exit the function
    }
    if (accountNumber.contains(' ')) {  // Check if account number contains spaces
        QMessageBox::critical(this, "Make Transaction Request", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (transactionAmount <= 0) {  // Check if transaction amount is invalid
        QMessageBox::warning(this, "Input Error", "Please enter a valid transfer amount.");  // Show warning message
        return;  // Exit the function
    }

    if (transactionType == "None") {  // Check if transaction type is not selected
        QMessageBox::warning(this, "Make Transaction Request", "Please enter Transaction Type.");  // Show warning message

        return;  // Exit the function
    }
    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "MakeTransaction";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request
    request["transaction_Amount"] = transactionAmount;  // Set the transaction amount in the request
    request["transaction_Type"] = transactionType;  // Set the transaction type in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_UserBack_Transaction_PB_clicked()
{
    ui->Login_page->setCurrentIndex(UserPage);  // Switch to the user page
}


/*=====================================================*/



/*****  delete it*****/
void MainWindow::on_UserTransfer_PB_clicked()
{
    QString fromAccountNumber = ui->fromAccountNumberLineEdit->text();
    QString toAccountNumber = ui->toAccountNumberLineEdit->text();
    int transferAmount = ui->transferAmountLineEdit->text().toInt();  // Assuming a QSpinBox for transfer amount

    // Validate the inputs
    if (fromAccountNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "From account number cannot be empty.");
        return;
    }

    if(fromAccountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "Input Error", "Wrong account number.please try again");
        return;

    }

    if (toAccountNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "To account number cannot be empty.");
        return;
    }

    if ( transferAmount <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid transfer amount.");
        return;
    }

    QJsonObject request;
    request["type"] = "TransferAmount";
    request["fromAccountNumber"] = fromAccountNumber;
    request["toAccountNumber"] = toAccountNumber;
    request["transferAmount"] = transferAmount;

    QJsonDocument jsonDoc(request);
    qInfo()<<"in transfer func"<<Qt::endl;
    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}
/***********************************************************************************************/
void MainWindow::on_UserTransfer_Back_PB_clicked()
{
    ui->Login_page->setCurrentIndex(UserPage);  // Switch to the user page
}

void MainWindow::on_UserTransfer_confirm_PB_clicked()
{
    QString fromAccountNumber = ui->fromAccountNumberLineEdit->text();  // Get the sender's account number from the input field
    QString toAccountNumber = ui->toAccountNumberLineEdit->text();  // Get the receiver's account number from the input field
    int transferAmount = ui->transferAmountLineEdit->text().toInt();  // Get the transfer amount from the input field, assuming a QSpinBox

    if (fromAccountNumber.isEmpty()) {  // Check if the sender's account number is empty
        QMessageBox::critical(this, "Make Transfer Request", "Please enter the sender account number.");  // Show critical error message

        return;  // Exit the function
    }
    if(fromAccountNumber != this->client_accountNumber) {  // Check if the sender's account number matches the stored account number
        QMessageBox::critical(this, "Make Transfer Request", "Wrong sender account number. Please try again");  // Show critical error message
        return;  // Exit the function
    }

    if (fromAccountNumber.contains(' ')) {  // Check if the sender's account number contains spaces
        QMessageBox::critical(this, "Make Transfer Request", "Invalid sender account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if(toAccountNumber.isEmpty()) {  // Check if the receiver's account number is empty
        QMessageBox::critical(this, "Make Transfer Request", "Please enter the receiver account number.");  // Show critical error message
        return;  // Exit the function
    }

    if (toAccountNumber.contains(' ')) {  // Check if the receiver's account number contains spaces
        QMessageBox::critical(this, "Make Transfer Request", "Invalid receiver account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (transferAmount <= 0) {  // Check if the transfer amount is less than or equal to zero
        QMessageBox::warning(this, "Make Transfer Request", "Please enter a valid transfer amount.");  // Show warning message

        return;  // Exit the function
    }
    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "TransferAmount";  // Set the type of request
    request["fromAccountNumber"] = fromAccountNumber;  // Set the sender's account number in the request
    request["toAccountNumber"] = toAccountNumber;  // Set the receiver's account number in the request
    request["transferAmount"] = transferAmount;  // Set the transfer amount in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

/***************************************   Admin page *************************/
void MainWindow::on_Admin_Logout_PB_clicked()
{
    ui->Login_page->setCurrentIndex(LoginPage);  // Switch to the login page
}

void MainWindow::on_Admin_GetAccountNo_PB_clicked()
{
    bool ok;  // Variable to check if input dialog was accepted
    QString username = QInputDialog::getText(this, tr("Get Account Number"), tr("Enter username:"), QLineEdit::Normal, "", &ok);  // Show input dialog to get username
    if (!ok || username.isEmpty()) {  // Check if input was not accepted or is empty
        QMessageBox::critical(this, "Get Account Request", "Username is required");  // Show critical error message
        return;  // Exit the function
    }

    if (username.contains(' ')) {  // Check if the username contains spaces
        QMessageBox::critical(this, "Get Account Request", "Invalid username. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "Admin_GetAccountNumber";  // Set the type of request
    request["username"] = username;  // Set the username in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_Admin_ViewAcountBalance_PB_clicked()
{
    bool ok;  // Variable to check if input dialog was accepted
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"), tr("Enter account number:"), QLineEdit::Normal, "", &ok);  // Show input dialog to get account number
    if (!ok || accountNumber.isEmpty()) {  // Check if input was not accepted or is empty
        QMessageBox::critical(this, "View Account Balance Request", "Account number is required");  // Show critical error message
        return;  // Exit the function
    }

    if (accountNumber.contains(' ')) {  // Check if the account number contains spaces
        QMessageBox::critical(this, "View Account Balance Request", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "Admin_ViewAccountBalance";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_Admin_ViewTransactionHistory_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminViewTransactionPage);  // Switch to the admin view transaction history page
}

void MainWindow::on_Back_AdminViewHistory_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);  // Switch to the admin page
}

void MainWindow::on_Display_AdminViewHistory_PB_clicked()
{
    QString accountNumber = ui->LineEdit_Admin_AccountNo_ViewHistory->text();  // Get the account number from the input field
    int count = ui->spinBox__Admin_Count_ViewHistory->value();  // Get the count from the spin box

    if (accountNumber.isEmpty()) {  // Check if the account number is empty
        QMessageBox::warning(this, "View Transaction", "Please enter account number.");  // Show warning message
        return;  // Exit the function
    }

    if (accountNumber.contains(' ')) {  // Check if the account number contains spaces
        QMessageBox::critical(this, "View Transaction Request", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "Admin_ViewTransactionHistory";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request
    request["count"] = count;  // Set the count in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

/**************************************************************************/
void MainWindow::on_Back_AdminViewBankDatabase_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);  // Switch to the admin page
}

void MainWindow::on_Admin_ViewBankDatabase_PB_clicked()
{
    // ui->Login_page->setCurrentIndex(AdminViewBankDatabasePage);  // Commented out code for switching to bank database view page

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "Admin_ViewBankDatabase";  // Set the type of request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

/************************************create user**************************/
void MainWindow::on_Admin_CreateNewUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminCreateUserPage);  // Switch to the admin create new user page
}

void MainWindow::on_Back_AdminCreateUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);  // Switch to the admin page
}

void MainWindow::on_Confirm_AdminCreateUser_PB_clicked()
{
    QString FullName = ui->LE_CreatUser_FullName->text();  // Get the full name from the input field
    int Age = ui->LE_CreatUser_Age->text().toInt();  // Get the age from the input field
    QString Username = ui->LE_CreatUser_UserName->text();  // Get the username from the input field
    QString Password = ui->LE_CreatUser_Password->text();  // Get the password from the input field
    QString Email = ui->LE_CreatUser_Email->text();  // Get the email from the input field
    QString confirmPassword = ui->LE_CreatUser_confirmPassword->text();  // Get the account number from the input field
    int Balance = 0;  // Set initial balance to 0
    QString Authority = "user";  // Set the authority level to "user"

    if (FullName.isEmpty()) {  // Check if the full name is empty
        QMessageBox::warning(this, "Create user Request", "Please enter Full name.");  // Show warning message

        return;  // Exit the function
    }

    if (Username.isEmpty()) {  // Check if the username is empty
        QMessageBox::warning(this, "Create user Request", "Please enter Username.");  // Show warning message

        return;  // Exit the function
    }

    if (Username.contains(' ')) {  // Check if the username contains spaces
        QMessageBox::critical(this, "Create user Request", "Invalid Username. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (Password.isEmpty()) {  // Check if the password is empty
        QMessageBox::warning(this, "Create user Request", "Please enter Password.");  // Show warning message

        return;  // Exit the function
    }

    if (Password.contains(' ')) {  // Check if the password contains spaces
        QMessageBox::critical(this, "Create user Request", "Invalid Password. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (Email.isEmpty()) {  // Check if the email is empty
        QMessageBox::warning(this, "Create user Request", "Please enter Email.");  // Show warning message

        return;  // Exit the function
    }

    if (Email.contains(' ')) {  // Check if the email contains spaces
        QMessageBox::critical(this, "Create user Request", "Invalid Email. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (confirmPassword.isEmpty()) {  // Check if the account number is empty
        QMessageBox::warning(this, "Create user Request", "Please confirm password.");  // Show warning message

        return;  // Exit the function
    }
    if (confirmPassword!=Password) {  // Check if the account number contains spaces
        QMessageBox::critical(this, "Create user Request", "confirmed password doesn't match. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    // Create a JSON object with the user data
    QJsonObject userData;  // Create JSON object for user data
    userData["FullName"] = FullName;  // Set the full name in the user data
    userData["Age"] = Age;  // Set the age in the user data
    userData["Username"] = Username;  // Set the username in the user data
    userData["Password"] = Password;  // Set the password in the user data
    userData["Email"] = Email;  // Set the email in the user data
   // userData["AccountNumber"] = AccountNo;  // Set the account number in the user data
    userData["Balance"] = Balance;  // Set the balance in the user data
    userData["Authority"] = Authority;  // Set the authority in the user data
    userData["Transactions"] = QJsonArray();  // Set an empty array for transactions

    // Create a request object
    QJsonObject request;  // Create JSON object for the request
    request["type"] = "Admin_CreateUser";  // Set the type of request
    request["data"] = userData;  // Set the user data in the request

    // Convert QJsonDocument to string
    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string

    // Send the JSON string to the server
    client.WriteData(jsonString);  // Send the request to the server
}

/***********************   delete user *************************/
void MainWindow::on_Admin_DeleteUser_PB_clicked()
{
    bool ok;  // Variable to check if input dialog was accepted
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"), tr("Enter account number:"), QLineEdit::Normal, "", &ok);  // Show input dialog to get account number
    if (!ok || accountNumber.isEmpty()) {  // Check if input was not accepted or is empty
        QMessageBox::critical(this, "Delete user Request", "Account number is required");  // Show critical error message
        return;  // Exit the function
    }

    if (accountNumber.contains(' ')) {  // Check if the account number contains spaces
        QMessageBox::critical(this, "Delete user Request", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "Admin_DeleteUser";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

/******************************update user****************************************/
void MainWindow::on_Admin_UpdateUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminUpdateUserPage);  // Switch to the admin update user page
}

void MainWindow::on_Confirm_AdminUpdateUser_PB_clicked()
{
    QString accountNumber = ui->LE_UpdateUser_AccountNumber->text();  // Get the account number from the input field
    QString fullName = ui->LE_UpdateUser_FullName->text();  // Get the full name from the input field
    int age = ui->LE_UpdateUser_Age->text().toInt();  // Get the age from the input field
    QString username = ui->LE_UpdateUser_UserName->text();  // Get the username from the input field
    QString password = ui->LE_UpdateUser_Password->text();  // Get the password from the input field
    QString email = ui->LE_UpdateUser_Email->text();  // Get the email from the input field

    if (accountNumber.isEmpty()) {  // Check if the account number is empty
        QMessageBox::warning(this, "Update user Request", "Please enter Account number.");  // Show warning message

        return;  // Exit the function
    }

    if (accountNumber.contains(' ')) {  // Check if the account number contains spaces
        QMessageBox::critical(this, "Update user Request", "Invalid account number. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (fullName.isEmpty()) {  // Check if the full name is empty
        QMessageBox::warning(this, "Update user Request", "Please enter Full name.");  // Show warning message

        return;  // Exit the function
    }

    if (age <= 0) {  // Check if the age is less than or equal to zero
        QMessageBox::critical(this, "Update user Request", "Invalid age. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (username.isEmpty()) {  // Check if the username is empty
        QMessageBox::warning(this, "Update user Request", "Please enter Username.");  // Show warning message

        return;  // Exit the function
    }

    if (username.contains(' ')) {  // Check if the username contains spaces
        QMessageBox::critical(this, "Update user Request", "Invalid Username. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (password.isEmpty()) {  // Check if the password is empty
        QMessageBox::warning(this, "Update user Request", "Please enter Password.");  // Show warning message

        return;  // Exit the function
    }

    if (password.contains(' ')) {  // Check if the password contains spaces
        QMessageBox::critical(this, "Update user Request", "Invalid Password. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    if (email.isEmpty()) {  // Check if the email is empty
        QMessageBox::warning(this, "Update user Request", "Please enter Email.");  // Show warning message

        return;  // Exit the function
    }

    if (email.contains(' ')) {  // Check if the email contains spaces
        QMessageBox::critical(this, "Update user Request", "Invalid Email. Please try again.");  // Show critical error message

        return;  // Exit the function
    }

    QJsonObject newData;  // Create a JSON object for the updated user data


    newData["FullName"] = fullName;  // Set the full name in the updated user data
    newData["Age"] = age;  // Set the age in the updated user data
    newData["Username"] = username;  // Set the username in the updated user data
    newData["Password"] = password;  // Set the password in the updated user data
    newData["Email"] = email;  // Set the email in the updated user data

    QJsonObject request;  // Create a JSON object for the request
    request["type"] = "Admin_UpdateUser";  // Set the type of request
    request["account_number"] = accountNumber;  // Set the account number in the request
    request["data"] = newData;  // Set the updated user data in the request

    QJsonDocument jsonDoc(request);  // Convert the request JSON object to a QJsonDocument

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);  // Serialize the JSON document to a compact string
    client.WriteData(jsonString);  // Send the request to the server
}

void MainWindow::on_Back_AdminUpdateUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);  // Switch back to the admin page
}

void MainWindow::on_checkBox_IP_stateChanged(int arg1)
{
    // Check if the checkbox is checked (arg1 == Qt::Checked)
    if (arg1 == Qt::Checked) {
        // Clear any existing text in the QLineEdit
        ui->leIP->clear();

        // Disable the QLineEdit, making it non-editable
        ui->leIP->setDisabled(true);

        // Set the background color of the QLineEdit to light gray
        ui->leIP->setStyleSheet("background-color: lightgray;");

        // Retrieve the local IP address and store it in a QString
        QString ip = getLocalIpAddress();

        // Set the retrieved IP address as the text in the QLineEdit
        ui->leIP->setText(ip);
    } else {
        // If the checkbox is unchecked, enable the QLineEdit, making it editable
        ui->leIP->setDisabled(false);

        // Set the background color of the QLineEdit to light blue
        ui->leIP->setStyleSheet("background-color: lightblue;");

        // Clear any existing text in the QLineEdit
        ui->leIP->clear();
    }
}


void MainWindow::on_checkBox_password_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
         ui->lineEdit_password->setEchoMode(QLineEdit::Normal);

    } else {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);  // Set the password field to hide input characters

    }
}

