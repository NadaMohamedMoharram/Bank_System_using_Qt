#include "MyServerHandler.h"  // Include the header file for the MyServerHandler class

MyServerHandler::MyServerHandler(qint32 ID, QObject *parent)
    : QThread{parent}  // Initialize QThread with optional parent object
{
    this->ID = ID;  // Set the connection ID

    // Connect signals from Admin_Class to slots in MyServerHandler
    connect(&adminFacade, &Admin_Class::sendMessageSignal, this, &MyServerHandler::sendMessage, Qt::DirectConnection);
    connect(&adminFacade, &Admin_Class::sendEmailSignal, this, &MyServerHandler::sendMessage, Qt::DirectConnection);
    connect(&userFacade, &User_Class::sendMessageSignal, this, &MyServerHandler::sendMessage, Qt::DirectConnection);
    connect(&userFacade, &User_Class::sendEmailSignal, this, &MyServerHandler::sendEmail, Qt::DirectConnection);
}

void MyServerHandler::run()
{
    Socket = new QTcpSocket();  // Create a new QTcpSocket instance
    Socket->setSocketDescriptor(ID);  // Set the socket descriptor to handle the connection
    connect(Socket, &QTcpSocket::readyRead, this, &MyServerHandler::onReadyRead, Qt::DirectConnection);  // Connect readyRead signal to onReadyRead slot
    connect(Socket, &QTcpSocket::disconnected, this, &MyServerHandler::onDisconnected, Qt::DirectConnection);  // Connect disconnected signal to onDisconnected slot
    exec();  // Start the event loop for this thread
}

void MyServerHandler::onReadyRead()
{
    logRequest("Received request from client:"+QString::number(this->ID));
    QByteArray encryptedMessage = Socket->readAll();  // Read all data from the socket

    QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"); // 32 bytes
    QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210"); // 16 bytes

    // Decrypt the message
    QByteArray decryptedMessage = QAESEncryption::Decrypt(QAESEncryption::AES_256, QAESEncryption::CBC, encryptedMessage, key, iv, QAESEncryption::PKCS7);

    if (decryptedMessage.isEmpty())
    {
        logRequest("Decryption failed, no data produced.");  // Log decryption failure
        return;
    }

    int paddingLength = decryptedMessage.at(decryptedMessage.size() - 1);  // Get the padding length
    if (paddingLength > 0 && paddingLength <= 16)
    {
        decryptedMessage.chop(paddingLength);  // Remove padding from the decrypted message
    }
    else
    {
        logRequest("Invalid padding length.");  // Log invalid padding length
        return;
    }

    QString decryptedMessageStr = QString(decryptedMessage);  // Convert decrypted message to QString

    // Split the message to extract the original data and the hash signature
    QStringList messageParts = decryptedMessageStr.split("|");
    if (messageParts.size() != 2)
    {
        logRequest("Invalid message format for hashing.");  // Log invalid message format
        return;
    }

    QString originalMessage = messageParts.at(0);  // Extract the original message
    QString receivedHashSignature = messageParts.at(1);  // Extract the received hash signature

    // Verify the hash signature using the secret key
    QByteArray secretKey = "IMT_Secret_key1234"; // Example secret key for hashing
    QByteArray recalculatedHashSignature = QCryptographicHash::hash(originalMessage.toUtf8() + secretKey, QCryptographicHash::Sha256).toHex();

    if (receivedHashSignature != recalculatedHashSignature)
    {
        logRequest("Invalid signature.");  // Log invalid signature
        return;
    }

    // Log the request to a file
    logRequest("original message:\n" + originalMessage);
    logRequest("received Hash Signature message:\n" + receivedHashSignature);
    logRequest("Encrypted message:\n" + QString(encryptedMessage));

    // Process the original message
    Operation(originalMessage);
}

void MyServerHandler::Operation(QString Operation)
{
    QJsonObject obj = MyServerHandler::ConvertToJsonObj(Operation);  // Convert the operation string to a QJsonObject
    QString type = obj["type"].toString();  // Get the type of operation

    // Perform actions based on the operation type
    if (type == "login") {
        QString username = obj["username"].toString();  // Get username
        QString password = obj["password"].toString();  // Get password
        MyServerHandler::OnLogin(username, password);  // Handle login operation
    }
    else if (type == "GetAccountNumber")
    {
        QString username = obj["username"].toString();  // Get username
        userFacade.GetAccountNumber(username);  // Request account number from userFacade
    }
    else if (type == "Admin_GetAccountNumber")
    {
        QString username = obj["username"].toString();  // Get username
        adminFacade.GetAccountNumber(username);  // Request account number from adminFacade
    }
    else if (type == "ViewAccountBalance")
    {
        QString accountNumber = obj["account_number"].toString();  // Get account number
        userFacade.GetBalance(accountNumber);  // Request account balance from userFacade
    }
    else if (type == "Admin_ViewAccountBalance")
    {
        QString accountNumber = obj["account_number"].toString();  // Get account number
        adminFacade.GetBalance(accountNumber);  // Request account balance from adminFacade
    }
    else if (type == "ViewTransactionHistory")
    {
        QString accountNumber = obj["account_number"].toString();  // Get account number
        int count = obj["count"].toInt();  // Get count of transactions
        userFacade.GetTransactionHistory(accountNumber, count);  // Request transaction history from userFacade
    }
    else if (type == "Admin_ViewTransactionHistory")
    {
        QString accountNumber = obj["account_number"].toString();  // Get account number
        int count = obj["count"].toInt();  // Get count of transactions
        adminFacade.GetTransactionHistory(accountNumber, count);  // Request transaction history from adminFacade
    }
    else if (type == "MakeTransaction")
    {
        qInfo() << "in server: MakeTransaction";  // Log that a transaction is being made

        QString accountNumber = obj["account_number"].toString();  // Get account number
        int transactionAmount = obj["transaction_Amount"].toInt();  // Get transaction amount
        QString transactionType = obj["transaction_Type"].toString();  // Get transaction type
        userFacade.MakeTransactionRequest(accountNumber, transactionAmount, transactionType);  // Request transaction from userFacade
    }
    else if (type == "TransferAmount")
    {
        qInfo() << "in server: TransferAmount";  // Log that a transfer is being made

        QString toAccountNumber = obj["toAccountNumber"].toString();  // Get destination account number
        QString fromAccountNumber = obj["fromAccountNumber"].toString();  // Get source account number
        int transferAmount = obj["transferAmount"].toInt();  // Get transfer amount
        userFacade.TransferAmountRequest(fromAccountNumber, toAccountNumber, transferAmount);  // Request transfer from userFacade
    }
    /*******************************admin *************************/
    else if (type == "Admin_ViewBankDatabase")
    {
        adminFacade.ViewBankDatabaseRequest();  // Request to view the bank database from adminFacade
    }
    else if (type == "Admin_CreateUser")
    {
        QJsonObject userData = obj["data"].toObject();  // Get user data
        adminFacade.CreateNewUserRequest(userData);  // Request to create a new user from adminFacade
    }
    else if (type == "Admin_DeleteUser")
    {
        QString accountNumber = obj["account_number"].toString();  // Get account number
        adminFacade.DeleteUserRequest(accountNumber);  // Request to delete a user from adminFacade
    }
    else if (type == "Admin_UpdateUser")
    {
        QString accountNumber = obj["account_number"].toString();  // Get account number
        QJsonObject userData = obj["data"].toObject();  // Get user data
        adminFacade.UpdateUserRequest(accountNumber, userData);  // Request to update user information from adminFacade
    }
    else
    {
        qInfo() << "invalid request" << Qt::endl;  // Log invalid request
    }
}

void MyServerHandler::onDisconnected()
{
    if (Socket->isOpen())
    {
        Socket->close();  // Close the socket
        qDebug() << "Client => " << ID << "has disconnected" << Qt::endl;  // Log disconnection
    }
}

void MyServerHandler::sendMessage(QString Message)
{
    if (Socket->isOpen())
    {
        Socket->write(Message.toUtf8());  // Write message to socket
        qDebug() << "message => " << Message << Qt::endl;  // Log message sent
        qDebug() << "My server Send Data to Client => " << Qt::endl;  // Log data sent
    }
    else
    {
        qDebug() << "Myserver Can't Send Data to Client => " << Qt::endl;  // Log failure to send data
    }
}

QJsonObject MyServerHandler::ConvertToJsonObj(QString Message)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(Message.toUtf8());  // Parse JSON document from message

    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        return jsonDoc.object();  // Return JSON object if valid
    } else {
        qWarning() << "Failed to parse JSON or the JSON is not an object.";  // Log JSON parsing failure
        return QJsonObject();  // Return an empty JSON object
    }
}

void MyServerHandler::OnLogin(QString username, QString password)
{
    QString authority = Data_Base.verifyCredentials(username, password);  // Verify user credentials
    QJsonObject response;  // Create a JSON object for the response
    DataBase db;  // Create a DataBase instance

    if (!authority.isEmpty())
    {
        qDebug() << "Login successful for user:" << username << "with authority:" << authority << Qt::endl;  // Log successful login

        response["status"] = "success";  // Set status to success
        response["authority"] = authority;  // Set authority in response
        response["account_number"] = db.getAccountNumber(username);  // Get account number and add to response
        sendMessage(QJsonDocument(response).toJson());  // Send response to client
        qDebug() << "Login successful for user:" << username << "with authority:" << authority << Qt::endl;  // Log successful login
    }
    else
    {
        response["status"] = "failed";  // Set status to failed
        sendMessage(QJsonDocument(response).toJson());  // Send response to client
        qDebug() << "Login failed for user:" << username << Qt::endl;  // Log failed login
        logRequest("Login failed for user");  // Log failed login
    }
}

void MyServerHandler::sendEmail(const QString &to, const QString &subject, const QString &body)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);  // Create a new QNetworkAccessManager instance

    QUrl url("https://nadamohamed2001.pythonanywhere.com/receive_email");  // URL for sending email
    QNetworkRequest request(url);  // Create a network request with the URL

    QUrlQuery query;  // Create a URL query
    query.addQueryItem("to", to);  // Add recipient email
    query.addQueryItem("subject", subject);  // Add email subject
    query.addQueryItem("body", body);  // Add email body

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  // Set content type header

    QNetworkReply *reply = manager->get(request, query.toString(QUrl::FullyEncoded).toUtf8());  // Send GET request with query

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qInfo() << "Email data sent successfully!" << Qt::endl;  // Log successful email send
        } else {
            qInfo() << "Error sending email data:" << reply->errorString() << Qt::endl;  // Log email send error
        }
        reply->deleteLater();  // Delete the reply object
    });
}

void MyServerHandler::logRequest(const QString &message)
{
    QFile logFile("D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\server_log.log");  // Create log file instance
    if (logFile.open(QIODevice::Append | QIODevice::Text))  // Open file for appending
    {
        QTextStream out(&logFile);  // Create a QTextStream for file writing
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";  // Write current date and time
        out << message << "\n\n";  // Write the log message
        logFile.close();  // Close the file
    }
    else
    {
        qWarning() << "Could not open log file for writing.";  // Log failure to open file
    }
}
