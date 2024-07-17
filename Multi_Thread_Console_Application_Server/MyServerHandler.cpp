#include "MyServerHandler.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>




MyServerHandler::MyServerHandler(qint32 ID,QObject *parent)
    : QThread{parent}
{
    this->ID = ID;
/////


}

MyServerHandler::~MyServerHandler()
{
  //  logFile.close();
}

void MyServerHandler::run()
{
  //  qDebug()<<"Client with ID: "<<ID<<" is running on thread "<<QThread::currentThreadId()<<Qt::endl;
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
    connect(Socket,&QTcpSocket::readyRead,this,&MyServerHandler::onReadyRead,Qt::DirectConnection);
    connect(Socket,&QTcpSocket::disconnected,this,&MyServerHandler::onDisconnected,Qt::DirectConnection);

   // sendMessage("Hello From My Server Dear client");
    exec();

}

void MyServerHandler::onReadyRead()
{

    // QByteArray ByteArr = Socket->readAll();


    // qDebug()<<"My Server Received Data From Client"<<Qt::endl;
    // Operation(QString(ByteArr));

    // qInfo()<<" receiveing encrypted request"<<Qt::endl;

    // QByteArray encryptedMessage = Socket->readAll();
    // qDebug() << "Encrypted message received from client: " << encryptedMessage;

    // // Define your AES encryption parameters
    // QAESEncryption::Aes aesLevel = QAESEncryption::AES_256; // or AES_128, AES_192
    // QAESEncryption::Mode aesMode = QAESEncryption::CBC; // or ECB, CFB, OFB
    // QAESEncryption::Padding aesPadding = QAESEncryption::PKCS7; // or ZERO, ISO

    // // Your key and IV (Initialization Vector) should be the same as used for encryption
    // // QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef"); // 256-bit key (32 bytes)
    // // QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210");  // 128-bit IV (16 bytes)
    // // Define your AES parameters
    // const QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef"); // Example: 32 bytes key for AES-256
    // const QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210");   // Example: 16 bytes IV for AES

    // // Decrypt the message
    // QByteArray decryptedMessage = QAESEncryption::Decrypt(aesLevel, aesMode, encryptedMessage, key, iv, aesPadding);

    // qDebug() << "Decrypted message: " << QString(decryptedMessage);
    // // Remove PKCS7 padding
    // int paddingLength = decryptedMessage.at(decryptedMessage.size() - 1);
    // if (paddingLength > 0 && paddingLength <= 16) {
    //     decryptedMessage.chop(paddingLength);
    // }

    /***************/
    /*
    QByteArray key = "0123456789abcdef0123456789abcdef"; // Encryption key
    QByteArray iv = "abcdef9876543210abcdef9876543210"; // Initialization vector
    // Decrypt the data
    QByteArray decryptedData = QAESEncryption::Decrypt(QAESEncryption::AES_128, QAESEncryption::CBC, decryptedData, key, iv, QAESEncryption::PKCS7);

    int padLength = decryptedData.at(decryptedData.length() - 1); // Get padding length
    decryptedData = decryptedData.left(decryptedData.length() - padLength); // Remove padding

    qInfo()<<"dataaa-->"<<QString(decryptedData)<<Qt::endl;

    logRequest(QString(decryptedData));
     Operation(QString(decryptedData));
     */
/********true code*************/
    /* QByteArray encryptedMessage = Socket->readAll();
    qDebug() << "Encrypted message received from client: " << encryptedMessage;

    // Define AES parameters
    QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef"); // 32 bytes key for AES-256
    QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210");  // 16 bytes IV for AES

    // Decrypt the message
    QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC, QAESEncryption::PKCS7);
    QByteArray decryptedMessage = encryption.decode(encryptedMessage, key, iv);

    // Check if the decryption produced any data
    if (decryptedMessage.isEmpty()) {
        qWarning() << "Decryption failed, no data produced.";
        return;
    }

    qDebug() << "Decrypted message: " << QString(decryptedMessage);

    // Handle the operation
    Operation(QString(decryptedMessage));

    */




    /*************/






    qInfo() << "Receiving encrypted request" << Qt::endl;

    QByteArray encryptedMessage = Socket->readAll();
    qDebug() << "Encrypted message received from client: " << encryptedMessage;

    // Define your AES decryption parameters
    QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"); // 32 bytes
    QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210"); // 16 bytes

    // Decrypt the message
    QByteArray decryptedMessage = QAESEncryption::Decrypt(
        QAESEncryption::AES_256,
        QAESEncryption::CBC,
        encryptedMessage,
        key,
        iv,
        QAESEncryption::PKCS7
        );

    if (decryptedMessage.isEmpty())
    {
        qWarning() << "Decryption failed, no data produced.";
        return;
    }

    qDebug() << "Decrypted message: " << QString(decryptedMessage);

    // int padLength = decryptedMessage.at(decryptedMessage.length() - 1); // Get padding length
    // decryptedMessage = decryptedMessage.left(decryptedMessage.length() - padLength); // Remove padding

    int paddingLength = decryptedMessage.at(decryptedMessage.size() - 1);
    if (paddingLength > 0 && paddingLength <= 16)
    {
        decryptedMessage.chop(paddingLength);
    }
    else
    {
        qWarning() << "Invalid padding length.";
        return;
    }

     logRequest(QString(decryptedMessage));

    qDebug() << "Decrypted message after remove padding: " << QString(decryptedMessage);
    Operation(QString(decryptedMessage));

}

void MyServerHandler::Operation(QString Operation)
{


    //qDebug()<<Operation<<Qt::endl;
     QJsonDocument jsonDoc = QJsonDocument::fromJson(Operation.toUtf8());
    QJsonObject obj= MyServerHandler::ConvertToJsonObj(Operation);
    // if (!jsonDoc.isNull() && jsonDoc.isObject()) {
    //      obj=jsonDoc.object();

    // } else {
    //     qWarning() << "Failed to parse JSON or the JSON is not an object.";
    //    // return QJsonObject();
    // }

    QString type = obj["type"].toString();

    if (type == "login") {
        QString username = obj["username"].toString();
        QString password = obj["password"].toString();

        MyServerHandler::OnLogin(username,password);

    }

    else if( (type == "GetAccountNumber" ) || (type == "Admin_GetAccountNumber")  )
    {
        QString username = obj["username"].toString();
        MyServerHandler::GetAccountNumber(username);
    }

    else if(  (type == "ViewAccountBalance") || (type == "Admin_ViewAccountBalance"))
    {
        QString accountNumber = obj["account_number"].toString();
        GetBalance(accountNumber);
    }

    else if ( (type == "ViewTransactionHistory") ||  (type == "Admin_ViewTransactionHistory"))
    {
        QString accountNumber = obj["account_number"].toString();
        int count = obj["count"].toInt();
        GetTransactionHistory(accountNumber, count);
    }

    else if(type == "MakeTransaction")
    {
        qInfo()<<"in server: MakeTransaction";

        QString accountNumber = obj["account_number"].toString();
        int transactionAmount = obj["transaction_Amount"].toInt();
        QString transactionType= obj["transaction_Type"].toString();
        MakeTransactionRequest(accountNumber, transactionAmount ,transactionType);
    }

   else if(type == "TransferAmount")
    {
        qInfo()<<"in server: TransferAmount";

        QString toAccountNumber= obj["toAccountNumber"].toString();
        QString fromAccountNumber = obj["fromAccountNumber"].toString();
        int transferAmount = obj["transferAmount"].toInt();
        TransferAmountRequest(fromAccountNumber, toAccountNumber ,transferAmount);
    }


    /*******************************admin *************************/
    else if(type == "Admin_ViewBankDatabase")
    {
        ViewBankDatabaseRequest();
    }


    else if(type == "Admin_CreateUser")
    {
         QJsonObject userData = obj["data"].toObject();
        CreateNewUserRequest(userData);
    }

    else if(type == "Admin_DeleteUser")
    {
        QString accountNumber = obj["account_number"].toString();
        DeleteUserRequest(accountNumber);
    }

    else if(type == "Admin_UpdateUser")
    {
        QString accountNumber = obj["account_number"].toString();
        QJsonObject userData = obj["data"].toObject();

        UpdateUserRequest(accountNumber,userData);
    }
    else{
        qInfo()<<"invalid request"<<Qt::endl;
    }



    // if(Operation == "Hello")
    // {
    //     sendMessage("Hello Dear Client");
    // }
    // else if(Operation == "What is your name")
    // {
    //     sendMessage("My name is Kerollos Server");
    // }
    // else if(Operation == "What is your Age")
    // {
    //     sendMessage("My Age is 27");
    // }
    // else
    // {
    //     QString str = "This is invalid request\n"
    //     "Hello\n"
    //     "What is your name\n"
    //     "What is your Age\n";
    //     sendMessage(str);
    // }
}

void MyServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {

        Socket->close();
        qDebug()<<"Client => "<<ID<<"has disconnected"<<Qt::endl;
    }
}

void MyServerHandler::sendMessage(QString Message)
{
    if(Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        qDebug()<<"My server Send Data to Client => "<<Qt::endl;
    }
    else
    {
        qDebug()<<"Myserver Can't Send Data to Client => "<<Qt::endl;
    }
}


QJsonObject MyServerHandler::ConvertToJsonObj(QString Message)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(Message.toUtf8());

    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        return jsonDoc.object();

    } else {
        qWarning() << "Failed to parse JSON or the JSON is not an object.";
         return QJsonObject();
    }

}
/***************************/

void MyServerHandler::OnLogin(QString username, QString password)
{
    QString authority= Data_Base.verifyCredentials(username, password);
    QJsonObject response;
    DataBase db;

    if (!authority.isEmpty())
    {
       // sendMessage("Login successful!");

        qDebug() << "Login successful for user:" << username << "with authority:" << authority << Qt::endl;

        response["status"] = "success";
        response["authority"] = authority;
        response["account_number"]= db.getAccountNumber(username);
        sendMessage(QJsonDocument(response).toJson());
        qDebug() << "Login successful for user:" << username << "with authority:" << authority << Qt::endl;
    }
    else
    {
        response["status"] = "failed";
        sendMessage(QJsonDocument(response).toJson());
        qDebug() << "Login failed for user:" << username << Qt::endl;
    }

    // if ( Data_Base.verifyCredentials(username, password) )
    // {
    //     sendMessage("Login successful!");
    //     qDebug() << "Login successful for user:" << username << Qt::endl;



    // }
    // else
    // {
    //     sendMessage("Login failed: Invalid username or password.");
    //     qDebug() << "Login failed for user:" << username << Qt::endl;
    // }
}

void MyServerHandler::GetAccountNumber(QString username)
{
    QJsonObject response;
   // if (loggedInUsers.contains(username) && loggedInUsers[username] == "user")
 //   {
        DataBase db;
        QString accountNumber = db.getAccountNumber(username);
        response["status"] = "success_GetAccountNumber";
        response["account_number"] = accountNumber;
  //  }
    // else
    // {
    //     response["status"] = "failed";
    //     response["account_number"] = "";
    // }
    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::GetBalance(const QString &accountNumber)
{
    DataBase db;
    int balance = db.getAccountBalance(accountNumber);

    QJsonObject response;
    response["status"] = "account_balance_response";
    response["account_number"] = accountNumber;
    response["balance"] = balance;
    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::GetTransactionHistory(const QString &accountNumber, int count)
{
    DataBase db;
    QJsonArray transactions = db.getTransactionHistory(accountNumber, count);

    QJsonObject response;
    response["status"] = "transaction_history_response";
    response["account_number"] = accountNumber;
    response["transactions"] = transactions;
    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::MakeTransactionRequest(const QString &accountNumber, int transactionAmount, const QString &transactionType)
{
    DataBase db;
    QJsonObject response;
    QString  emailBody;
    if (transactionType =="Withdrow")
    {
        transactionAmount*=-1;
    }

    bool transactionResult = db.makeTransaction(accountNumber, transactionAmount);
    response["status"] = "transaction_amount_response";
    if (transactionResult==true)
    {
    response["transaction_Result"] = "Transaction successful";
        emailBody = QString("Transaction success.");

    }
    else
    {
     response["transaction_Result"] = "Transaction failed";
        emailBody = QString("Transaction failed.");

    }


    QString to = "nadamohamedmoharram@gmail.com";  // Replace with the actual recipient email
    QString subject = "Transaction Notification";

     sendEmail(to, subject, emailBody);

    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::TransferAmountRequest(const QString &fromAccountNumber, const QString &toAccountNumber, int transferAmount)
{
    qInfo()<<"in server handler: TransferAmountRequest func";

    DataBase db;
    QJsonObject response;
    bool transferResult = db.transferAmount(fromAccountNumber, toAccountNumber, transferAmount);
    QString  emailBody;
    response["status"] = "transfer_response";
    if (transferResult==true)
    {
        response["transsfer_Result"] = "Transfer successful";
         emailBody = QString("Transfer of %1 from account %2 to account %3 was successful.")
                        .arg(transferAmount)
                        .arg(fromAccountNumber)
                        .arg(toAccountNumber);
    }
    else
    {
        response["transsfer_Result"] = "Transfer failed";
          emailBody = QString("Transfer of %1 from account %2 to account %3 was failed.")
                                .arg(transferAmount)
                                .arg(fromAccountNumber)
                                .arg(toAccountNumber);
    }


    sendMessage(QJsonDocument(response).toJson());

    QString to = "nmo12416@gmail.com";  // Replace with the actual recipient email
    QString subject = "Transfer Notification";

    sendEmail(to, subject, emailBody);

}

void MyServerHandler::ViewBankDatabaseRequest()
{
    DataBase db;
    QJsonObject response;
    QJsonArray Data=db.viewBankDatabase();
    response["status"] = "ViewBankDatabase_response";
    response["data"]=Data;
     sendMessage(QJsonDocument(response).toJson());

}

void MyServerHandler::CreateNewUserRequest(const QJsonObject &userData)
{
    DataBase db;
    QJsonObject response;
    bool CreateUserResult = db.createNewUser(userData);

    response["status"] = "CreateUser_response";
    if (CreateUserResult==true)
        response["NewUser_Result"] = "Create new user successful";
    else
        response["NewUser_Result"] = "Create new user failed. username or acount number is already used";


    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::DeleteUserRequest(const QString &accountNumber)
{
    DataBase db;
    QJsonObject response;
    bool DeleteUserResult = db.deleteUser(accountNumber);

    response["status"] = "DeleteUser_response";
    if (DeleteUserResult==true)
        response["DeleteUser_Result"] = "Delete user successful";
    else
        response["DeleteUser_Result"] = "Delete user failed.";


    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::UpdateUserRequest(const QString &accountNumber, const QJsonObject &userData)
{
    DataBase db;
    QJsonObject response;
    bool UpdateUserResult = db.updateUser(accountNumber , userData);

    response["status"] = "UpdateUser_response";
    if (UpdateUserResult==true)
        response["UpdateUser_Result"] = "Update user successful";
    else
        response["UpdateUser_Result"] = "Update user failed.";


    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::sendEmail(const QString &to, const QString &subject, const QString &body)
{

    QProcess process;

    // Path to your batch script
    QString batchFilePath = "D:\\ITIDA_Scholarship\\Final project\\send_email.bat";

    // Prepare arguments
    QStringList arguments;
    arguments << to << subject << body;

    // Start the batch script with arguments
    qDebug() << "Starting batch script with arguments:" << arguments;
    process.start(batchFilePath, arguments);
    if (!process.waitForFinished())
    {
        qDebug() << "Failed to run batch script:" << process.errorString();
        return;
    }

    // Read and display the output or error
    QString output = process.readAllStandardOutput();
    QString error = process.readAllStandardError();
    if (!error.isEmpty())
    {
        qDebug() << "Error sending email:" << error;
    }
    else
    {
        qDebug() << "Output:" << output;
    }



    }

void MyServerHandler::logRequest(const QString &message)
    {     /*   QFile logFile("D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\server_log.log");
        if (logFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&logFile);
            out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << ": " << request << "\n";
            logFile.close();
        }
        */


        QFile logFile("D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\server_log.log");
        if (logFile.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&logFile);
            out << message << "\n";
            logFile.close();
        }
        else
        {
            qWarning() << "Could not open log file for writing.";
        }
    }

