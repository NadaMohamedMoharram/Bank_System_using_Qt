#include "DataBase.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent},FilePath{"D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\Database\\LoginDB.json"}
{
    initDataBase();
}

void DataBase::addObject(QString name, qint32 age)
{
    initDataBase();
    qint32 lastId = jsonDataBase.back()["ID"].toInt();
    QJsonObject newObj;
    newObj["ID"] = lastId +1;
    newObj["Name"] = name;
    newObj["Age"] = age;
    jsonDataBase.append(newObj);
    QJsonArray jsonArr;
    for(auto&vv : jsonDataBase)
    {
        jsonArr.append(vv);
    }
    QFile file(FilePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}

void DataBase::updateObject(qint32 id, QString name, qint32 age)
{
    initDataBase();
    for(auto&vv:jsonDataBase)
    {
        if(vv["ID"].toInt() ==id)
        {
            vv["Name"] = name;
            vv["Age"] = age;
            break;
        }
    }
    QJsonArray jsonArr;
    for(auto&vv : jsonDataBase)
    {
        jsonArr.append(vv);
    }
    QFile file(FilePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}

void DataBase::deleteObject(qint32 id)
{
    initDataBase();
    QJsonArray jsonArr;
    for(auto&vv:jsonDataBase)
    {
        if(vv["ID"].toInt() != id)
        {
            jsonArr.append(vv);
        }
    }
    QFile file(FilePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}

void DataBase::showDataBase()
{
    initDataBase();
    for(auto&vv : jsonDataBase)
    {
        QJsonDocument jsonDoc = QJsonDocument(vv);
        QString jsonStr = QString::fromUtf8(jsonDoc.toJson());
        qDebug().noquote()<<jsonStr<<Qt::endl;
    }
}

void DataBase::initDataBase()
{
    jsonDataBase.clear();
    QFile file(FilePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray byteArr = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);
        QJsonArray JsonArr = jsonDoc.array();
        for(int i=0;i<JsonArr.size();i++)
        {
            QJsonObject jsonObj= JsonArr[i].toObject();
            jsonDataBase<<jsonObj;
        }
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}




QString DataBase::verifyCredentials(const QString& username, const QString& password)
{
    initDataBase();
    for (const auto& user : jsonDataBase)
    {
        if (user["Username"].toString() == username && user["Password"].toString() == password)
        {
            return user["Autority"].toString();
        }
    }
    return QString();  // Return an empty string if the user is not found
}


QString DataBase::getAccountNumber(const QString& username)
{
    initDataBase();
    for (const auto& user : jsonDataBase)
    {
        if (user["Username"].toString() == username)
        {
            return user["AccountNumber"].toString();
        }
    }
    return QString(); // Return an empty string if the user is not found
}

int DataBase::getAccountBalance(const QString &accountNumber)
{
    initDataBase();
    for (const auto& record : jsonDataBase) {
        if (record["AccountNumber"].toString() == accountNumber) {
          //  return record["Balance"].toString();
            return record["Balance"].toInt();
        }
    }
    return 0; // Return 0 if the account number is not found
}

QJsonArray DataBase::getTransactionHistory(const QString &accountNumber, int count)
{

/**********************************************/
    // initDataBase();
    // QJsonArray transactions;

    // for (const auto& record : jsonDataBase) {
    //     if (record["AccountNumber"].toString() == accountNumber) {
    //         QJsonArray transactionArray = record["Transactions"].toArray();
    //         QVector<QJsonObject> transactionVector;

    //         for (const auto& transaction : transactionArray) {
    //             transactionVector.append(transaction.toObject());
    //         }

    //         std::sort(transactionVector.begin(), transactionVector.end(), [](const QJsonObject &a, const QJsonObject &b) {
    //             return a["date"].toString() > b["date"].toString();
    //         });

    //         for (int i = 0; i < count && i < transactionVector.size(); ++i) {
    //             transactions.append(transactionVector[i]);
    //         }
    //         break;
    //     }
    // }

    // return transactions;
    /************************************************************/
    // initDataBase();
    // QJsonArray transactions;

    // for (const auto& record : jsonDataBase) {
    //     if (record["AccountNumber"].toString() == accountNumber) {
    //         QJsonArray transactionArray = record["Transactions"].toArray();
    //         QVector<QJsonObject> transactionVector;

    //         for (const auto& transaction : transactionArray) {
    //             transactionVector.append(transaction.toObject());
    //         }

    //         std::sort(transactionVector.begin(), transactionVector.end(), [](const QJsonObject &a, const QJsonObject &b) {
    //             return QDate::fromString(a["date"].toString(), "dd-MM-yyyy") > QDate::fromString(b["date"].toString(), "dd-MM-yyyy");
    //         });

    //         for (int i = 0; i < count && i < transactionVector.size(); ++i) {
    //             transactions.append(transactionVector[i]);
    //         }
    //         break;
    //     }
    // }

    // return transactions;
    /*********************************************************/
initDataBase();
QJsonArray transactions;

for (const auto& record : jsonDataBase) {
    if (record["AccountNumber"].toString() == accountNumber) {
        QJsonArray transactionArray = record["Transactions"].toArray();
        QVector<QJsonObject> transactionVector;

        for (const auto& transaction : transactionArray) {
            transactionVector.append(transaction.toObject());
        }

        std::sort(transactionVector.begin(), transactionVector.end(), [](const QJsonObject &a, const QJsonObject &b) {
            return QDate::fromString(a["date"].toString(), "dd-MM-yyyy") > QDate::fromString(b["date"].toString(), "dd-MM-yyyy");
        });

        for (int i = 0; i < count && i < transactionVector.size(); ++i) {
            transactions.append(transactionVector[i]);
        }
        break;
    }
}

return transactions;

}

bool DataBase::makeTransaction(const QString &accountNumber, int transactionAmount)
{
    // initDataBase();
    // for (auto& record : jsonDataBase) {
    //     if (record["AccountNumber"].toString() == accountNumber) {
    //         int currentBalance = record["Balance"].toInt();
    //         if (transactionAmount < 0 && (currentBalance < qAbs(transactionAmount))) {
    //             return false; // Insufficient funds for withdrawal
    //         }
    //         record["Balance"] = currentBalance + transactionAmount;

    //         QJsonObject transaction;
    //         transaction["date"] = QDate::currentDate().toString("dd-MM-yyyy");
    //         transaction["Amount"] = transactionAmount;
    //         transaction["type"] = transactionAmount >= 0 ? "deposit" : "withdrawal";
    //         record["Transactions"].toArray().append(transaction);

    //  /*-------------------> how to make */       saveDataBase();
    //         return true;
    //     }
    // }
    // return false; // Account number not found


    initDataBase();
    for (auto& record : jsonDataBase) {
        if (record["AccountNumber"].toString() == accountNumber) {
            int currentBalance = record["Balance"].toInt();
            if (transactionAmount < 0 && (currentBalance < qAbs(transactionAmount))) {
                return false; // Insufficient funds for withdrawal
            }
            record["Balance"] = currentBalance + transactionAmount;

            QJsonObject transaction;
            transaction["date"] = QDate::currentDate().toString("dd-MM-yyyy");
            transaction["Amount"] = transactionAmount;
            transaction["type"] = transactionAmount >= 0 ? "deposit" : "withdrawal";

            QJsonArray transactions = record["Transactions"].toArray();
            transactions.append(transaction);
            record["Transactions"] = transactions;

            saveDataBase();
            return true;
        }
    }
    return false; // Account number not found

}

bool DataBase::transferAmount(const QString &fromAccountNumber, const QString &toAccountNumber, int transferAmount)
{
    qInfo()<<"in database"<<Qt::endl;
    initDataBase(); // Ensure the database is initialized

    QJsonObject fromRecord;
    QJsonObject toRecord;
    int fromRecordIndex = -1;
    int toRecordIndex = -1;

    for (int i = 0; i < jsonDataBase.size(); ++i) {
        QJsonObject record = jsonDataBase[i];
        if (record["AccountNumber"].toString() == fromAccountNumber) {
            fromRecord = record;
            fromRecordIndex = i;
        }
        if (record["AccountNumber"].toString() == toAccountNumber) {
            toRecord = record;
            toRecordIndex = i;
        }
    }

    if (fromRecordIndex == -1 || toRecordIndex == -1) {
        return false; // Account number not found
    }

    int fromBalance = fromRecord["Balance"].toInt();
    if (transferAmount <= 0 || fromBalance < transferAmount) {
        return false; // Invalid transfer amount or insufficient funds
    }

    int toBalance = toRecord["Balance"].toInt();
    fromRecord["Balance"] = fromBalance - transferAmount;
    toRecord["Balance"] = toBalance + transferAmount;

    QJsonObject transactionFrom;
    transactionFrom["date"] = QDate::currentDate().toString("dd-MM-yyyy");
    transactionFrom["Amount"] = -transferAmount;
    transactionFrom["type"] = "transfer_to_" + toAccountNumber;

    QJsonArray fromTransactions = fromRecord["Transactions"].toArray();
    fromTransactions.append(transactionFrom);
    fromRecord["Transactions"] = fromTransactions;

    QJsonObject transactionTo;
    transactionTo["date"] = QDate::currentDate().toString("dd-MM-yyyy");
    transactionTo["Amount"] = transferAmount;
    transactionTo["type"] = "transfer_from_" + fromAccountNumber;

    QJsonArray toTransactions = toRecord["Transactions"].toArray();
    toTransactions.append(transactionTo);
    toRecord["Transactions"] = toTransactions;

    // Update the records in the jsonDataBase array
    jsonDataBase[fromRecordIndex] = fromRecord;
    jsonDataBase[toRecordIndex] = toRecord;

    saveDataBase();
    return true;
}

QJsonArray DataBase::viewBankDatabase()
{
    initDataBase(); // Ensure the database is initialized

    QJsonArray databaseArray;
    for (const auto& record : jsonDataBase) {
        QJsonObject accountDetails;
        accountDetails["Username"] = record["Username"].toString();
        accountDetails["AccountNumber"] = record["AccountNumber"].toString();
        accountDetails["Autority"] = record["Autority"].toString();
        accountDetails["Balance"] = record["Balance"].toInt();
        accountDetails["Email"] = record["Email"].toString();
        accountDetails["FullName"] = record["FullName"].toString();
        accountDetails["Age"] = record["Age"].toInt();
        accountDetails["Password"] = record["Password"].toString();

        QJsonArray transactions = record["Transactions"].toArray();
        accountDetails["Transactions"] = transactions;

        databaseArray.append(accountDetails);
    }

    return databaseArray;
}

bool DataBase::createNewUser(const QJsonObject &userData)
{
    initDataBase();

    QString newUsername = userData["Username"].toString();
    QString newAccountNumber = userData["AccountNumber"].toString();

    // Check if the username or account number already exists
    for (const QJsonObject &record : jsonDataBase) {
        if (record["Username"].toString() == newUsername || record["AccountNumber"].toString() == newAccountNumber) {
            return false; // Username or account number already exists
        }
    }

    // Add the new user to the database
    jsonDataBase.append(userData);

    // Save the updated database
    saveDataBase();

    return true;
}

bool DataBase::deleteUser(const QString &accountNumber)
{
    initDataBase();

    // Find the user with the given account number and remove them
    for (int i = 0; i < jsonDataBase.size(); ++i) {
        if (jsonDataBase[i]["AccountNumber"].toString() == accountNumber) {
            jsonDataBase.removeAt(i);
            saveDataBase();
            return true; // User deleted successfully
        }
    }
    return false; // Account number not found
}

bool DataBase::updateUser(const QString &accountNumber, const QJsonObject &newData)
{
    initDataBase();

    // Find the user with the given account number and update their data
    for (auto &record : jsonDataBase) {
        if (record["AccountNumber"].toString() == accountNumber) {
            for (auto it = newData.begin(); it != newData.end(); ++it) {
                record[it.key()] = it.value();
            }
            saveDataBase();
            return true; // User updated successfully
        }
    }
    return false; // Account number not found
}


// QString DataBase::GetUserAuthority(const QString &username)
// {
//     initDataBase();
//     for (const auto& user : jsonDataBase)
//     {
//         if (user["Username"].toString() == username )
//         {
//             return user["Autority"].toString();
//         }
//     }
//     return QString();  // Return an empty string if the user is not found
// }
/****************************/


// #include "DataBase.h"


// DataBase::DataBase(QObject *parent)
//     : QObject{parent},
//    FilePath{"D:\\ITIDA_Scholarship\\Task_Qt\\JSON\\untitled\\DataBaseFile.json"}
// {
//     initDataBase();
// }

// void DataBase::addObject(QString category, QString name, QString password)
// {
//     initDataBase();

//     if (!jsonDataBase.contains(category) || !jsonDataBase[category].isArray()) {
//         qDebug() << "Invalid category or not an array.";
//         return;
//     }

//     QJsonArray categoryArray = jsonDataBase[category].toArray();
//     QJsonObject newObj;
//     newObj[name] = QJsonObject{{"password", password}};
//     categoryArray.append(newObj);

//     jsonDataBase[category] = categoryArray;

//     writeDataBase();
// }

// void DataBase::updateObject(QString category, QString name, QString password)
// {
//     initDataBase();

//     if (!jsonDataBase.contains(category) || !jsonDataBase[category].isArray()) {
//         qDebug() << "Invalid category or not an array.";
//         return;
//     }

//     QJsonArray categoryArray = jsonDataBase[category].toArray();
//     bool found = false;
//     for (auto &value : categoryArray) {
//         QJsonObject obj = value.toObject();
//         if (obj.contains(name)) {
//             obj[name]["password"] = password;
//             value = obj;
//             found = true;
//             break;
//         }
//     }

//     if (found) {
//         jsonDataBase[category] = categoryArray;
//         writeDataBase();
//     } else {
//         qDebug() << "Object not found.";
//     }
// }

// void DataBase::deleteObject(QString category, QString name)
// {
//     initDataBase();

//     if (!jsonDataBase.contains(category) || !jsonDataBase[category].isArray()) {
//         qDebug() << "Invalid category or not an array.";
//         return;
//     }

//     QJsonArray categoryArray = jsonDataBase[category].toArray();
//     QJsonArray newArray;
//     for (auto &value : categoryArray) {
//         QJsonObject obj = value.toObject();
//         if (!obj.contains(name)) {
//             newArray.append(value);
//         }
//     }

//     jsonDataBase[category] = newArray;
//     writeDataBase();
// }

// void DataBase::showDataBase()
// {
//     initDataBase();
//     qDebug().noquote() << QJsonDocument(jsonDataBase).toJson() << Qt::endl;
// }

// void DataBase::initDataBase()
// {
//     jsonDataBase = QJsonObject();
//     QFile file(FilePath);
//     if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         QByteArray byteArr = file.readAll();
//         QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);
//         jsonDataBase = jsonDoc.object();
//         file.close();
//     } else {
//         qDebug() << "Can't Open the database file" << Qt::endl;
//     }
// }

// void DataBase::writeDataBase()
// {
//     QFile file(FilePath);
//     if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
//         file.write(QJsonDocument(jsonDataBase).toJson());
//         file.close();
//     } else {
//         qDebug() << "Can't Open the database file" << Qt::endl;
//     }
// }

void DataBase::saveDataBase()
{
    // QJsonArray jsonArr;
    // for (const auto& record : jsonDataBase)
    // {
    //     jsonArr.append(record);
    // }
    // QFile file(FilePath);
    // if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // {
    //     file.write(QJsonDocument(jsonArr).toJson());
    //     file.close();
    // }
    // else
    // {
    //     qDebug() << "Can't Open the database file" << Qt::endl;
    // }
    QJsonArray jsonArr;
    for (const auto& record : jsonDataBase) {
        jsonArr.append(record);
    }

    QFile file(FilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    } else {
        qDebug() << "Can't Open the database file" << Qt::endl;
    }
}


