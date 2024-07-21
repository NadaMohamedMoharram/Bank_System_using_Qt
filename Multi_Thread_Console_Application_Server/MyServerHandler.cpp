#include "MyServerHandler.h"

MyServerHandler::MyServerHandler(qint32 ID,QObject *parent)
    : QThread{parent}
{
    this->ID = ID;
    // Connect the signal from Admin_Class to the slot in MyServerHandler
    connect(&adminFacade, &Admin_Class::sendMessageSignal, this, &MyServerHandler::sendMessage ,Qt::DirectConnection);
    connect(&adminFacade, &Admin_Class::sendEmailSignal, this, &MyServerHandler::sendMessage ,Qt::DirectConnection);
    connect(&userFacade, &User_Class::sendMessageSignal, this, &MyServerHandler::sendMessage ,Qt::DirectConnection);
    connect(&userFacade, &User_Class::sendEmailSignal, this, &MyServerHandler::sendEmail ,Qt::DirectConnection);
}



void MyServerHandler::run()
{
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
    connect(Socket,&QTcpSocket::readyRead,this,&MyServerHandler::onReadyRead,Qt::DirectConnection);
    connect(Socket,&QTcpSocket::disconnected,this,&MyServerHandler::onDisconnected,Qt::DirectConnection);
    exec();
}

void MyServerHandler::onReadyRead()
{

    QByteArray encryptedMessage = Socket->readAll();

    QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"); // 32 bytes
    QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210"); // 16 bytes

    // Decrypt the message
    QByteArray decryptedMessage = QAESEncryption::Decrypt(QAESEncryption::AES_256,QAESEncryption::CBC,encryptedMessage,key,iv,QAESEncryption::PKCS7);

    if (decryptedMessage.isEmpty())
    {
        logRequest( "Decryption failed, no data produced.");
        return;
    }

    int paddingLength = decryptedMessage.at(decryptedMessage.size() - 1);
    if (paddingLength > 0 && paddingLength <= 16)
    {
        decryptedMessage.chop(paddingLength);
    }
    else
    {
        logRequest("Invalid padding length.");
        return;
    }


    QString decryptedMessageStr = QString(decryptedMessage);

    // Split the message to extract the original data and the hash signature
    QStringList messageParts = decryptedMessageStr.split("|");
    if (messageParts.size() != 2)
    {
        logRequest( "Invalid message format for hashing.");
        return;
    }

    QString originalMessage = messageParts.at(0);
    QString receivedHashSignature = messageParts.at(1);

    // Verify the hash signature using the secret key
    QByteArray secretKey = "IMT_Secret_key1234"; // Example secret key for hashing
    QByteArray recalculatedHashSignature = QCryptographicHash::hash(originalMessage.toUtf8() + secretKey, QCryptographicHash::Sha256).toHex();

    if (receivedHashSignature != recalculatedHashSignature)
    {
        logRequest("Invalid signature.");
        return;
    }

    // Log the request to a file
    logRequest("original message:\n"+originalMessage);
    logRequest("received Hash Signature message:\n"+receivedHashSignature);
    logRequest("Encrypted message:\n"+QString(encryptedMessage));
    // Process the original message
    Operation(originalMessage);
}




void MyServerHandler::Operation(QString Operation)
{
    QJsonObject obj= MyServerHandler::ConvertToJsonObj(Operation);
    QString type = obj["type"].toString();

    if (type == "login") {
        QString username = obj["username"].toString();
        QString password = obj["password"].toString();

        MyServerHandler::OnLogin(username,password);

    }

    else if( type == "GetAccountNumber"   )
    {
        QString username = obj["username"].toString();

        userFacade.GetAccountNumber(username);
    }

    else if( type == "Admin_GetAccountNumber"  )
    {
        QString username = obj["username"].toString();

        adminFacade.GetAccountNumber(username);
    }


    else if(  (type == "ViewAccountBalance"))
    {
        QString accountNumber = obj["account_number"].toString();
        userFacade.GetBalance(accountNumber);
    }

    else if( (type == "Admin_ViewAccountBalance"))
    {
        QString accountNumber = obj["account_number"].toString();
       adminFacade.GetBalance(accountNumber);
    }

    else if ( type == "ViewTransactionHistory")
    {
        QString accountNumber = obj["account_number"].toString();
        int count = obj["count"].toInt();
        userFacade.GetTransactionHistory(accountNumber, count);
    }
    else if (type == "Admin_ViewTransactionHistory")
    {
        QString accountNumber = obj["account_number"].toString();
        int count = obj["count"].toInt();
        adminFacade.GetTransactionHistory(accountNumber, count);
    }

    else if(type == "MakeTransaction")
    {
        qInfo()<<"in server: MakeTransaction";

        QString accountNumber = obj["account_number"].toString();
        int transactionAmount = obj["transaction_Amount"].toInt();
        QString transactionType= obj["transaction_Type"].toString();
        userFacade.MakeTransactionRequest(accountNumber, transactionAmount ,transactionType);
    }

   else if(type == "TransferAmount")
    {
        qInfo()<<"in server: TransferAmount";

        QString toAccountNumber= obj["toAccountNumber"].toString();
        QString fromAccountNumber = obj["fromAccountNumber"].toString();
        int transferAmount = obj["transferAmount"].toInt();
        userFacade.TransferAmountRequest(fromAccountNumber, toAccountNumber ,transferAmount);
    }


    /*******************************admin *************************/
    else if(type == "Admin_ViewBankDatabase")
    {
        adminFacade.ViewBankDatabaseRequest();
    }


    else if(type == "Admin_CreateUser")
    {
         QJsonObject userData = obj["data"].toObject();
       adminFacade.CreateNewUserRequest(userData);
    }

    else if(type == "Admin_DeleteUser")
    {
        QString accountNumber = obj["account_number"].toString();
        adminFacade.DeleteUserRequest(accountNumber);
    }

    else if(type == "Admin_UpdateUser")
    {
        QString accountNumber = obj["account_number"].toString();
        QJsonObject userData = obj["data"].toObject();

       adminFacade.UpdateUserRequest(accountNumber,userData);
    }
    else{
        qInfo()<<"invalid request"<<Qt::endl;
    }

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
        qDebug()<<"message => "<<Message<<Qt::endl;

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
/****************************************************************/

void MyServerHandler::OnLogin(QString username, QString password)
{
    QString authority= Data_Base.verifyCredentials(username, password);
    QJsonObject response;
    DataBase db;

    if (!authority.isEmpty())
    {

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
        logRequest("Login failed for user");
    }


}


void MyServerHandler::sendEmail(const QString &to, const QString &subject, const QString &body)
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url("https://nadamohamed2001.pythonanywhere.com/receive_email");
    QNetworkRequest request(url);

    QUrlQuery query;
    query.addQueryItem("to", to);
    query.addQueryItem("subject", subject);
    query.addQueryItem("body", body);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply *reply = manager->get(request, query.toString(QUrl::FullyEncoded).toUtf8());

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
           // logRequest( "Email data sent successfully!");
            qInfo()<< "Email data sent successfully!"<<Qt::endl;

        } else {
            qInfo()<< "Error sending email data:"<< reply->errorString()<<Qt::endl;
        }
        reply->deleteLater();
    });


}


void MyServerHandler::logRequest(const QString &message)
    {
        QFile logFile("D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\server_log.log");
        if (logFile.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&logFile);
            out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") <<"\n";
            out << message << "\n\n";
            logFile.close();
        }
        else
        {
            qWarning() << "Could not open log file for writing.";
        }
    }

