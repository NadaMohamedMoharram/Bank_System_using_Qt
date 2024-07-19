#include "MyClient.h"
#include<QProcess>
#include <QCryptographicHash>


/********/
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
/*************/

MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    connect(&socket,&QTcpSocket::connected,this,&MyClient::onConnection);
    connect(&socket,&QTcpSocket::disconnected,this,&MyClient::onDisconnected);
    connect(&socket,&QTcpSocket::errorOccurred,this,&MyClient::onErrorOccurred);
    connect(&socket,&QTcpSocket::stateChanged,this,&MyClient::onStateChanged);
    connect(&socket,&QTcpSocket::readyRead,this,&MyClient::onReadyRead);

}

void MyClient::ConnectToDevice(QString ip, qint32 port)
{
    if(socket.isOpen())
    {
        if((this->ip == ip)&&(this->port == port))
        {
            return;
        }
        else
        {
            socket.close();
            this->port = port;
            this->ip = ip;
            socket.connectToHost(this->ip,this->port);
            qInfo()<<"connecting to server.......";


        }
    }
    else
    {
        this->port = port;
        this->ip = ip;
        socket.connectToHost(this->ip,this->port);
        qInfo()<<"connecting to server.......";
    }
}

void MyClient::Disconnect()
{
    if(socket.isOpen())
    {
        socket.close();
    }
}

void MyClient::WriteData(QString data)
{
   /* if(socket.isOpen())
    {
        qInfo()<<"inside send request"<<Qt::endl;
        // Define your AES parameters
        // Define your AES parameters
        qInfo()<<"before encryptedDataNew"<<data<<Qt::endl;


        // Define your AES parameters
        const QByteArray key = "0123456789abcdef0123456789abcdef"; // 32 bytes key for AES-256
        const QByteArray iv = "abcdef9876543210abcdef9876543210";   // 16 bytes IV for AES

        QByteArray rawData = data.toUtf8();
         qInfo()<<"rawData"<<rawData<<Qt::endl;
        // Encrypt the data
        QByteArray encryptedData = QAESEncryption::Crypt(
            QAESEncryption::AES_256, // AES level (AES_128, AES_192, or AES_256)
            QAESEncryption::CBC,     // Mode (ECB, CBC, CFB, OFB)
            rawData,                 // Raw data to encrypt
            key,                     // Encryption key
            iv,                      // Initialization vector
            QAESEncryption::PKCS7    // Padding (ZERO, PKCS7, ISO)
            );

             qInfo()<<"encryptedDataNew"<<encryptedData<<Qt::endl;
            socket.write(encryptedData);
            qInfo()<<" send encrypted request"<<Qt::endl;

         // QString encryptedDataNew = QString(encryptedData);

         // socket.write(encryptedDataNew.toUtf8());

       // socket.write(data.toUtf8());


    }*/


   /**********true***********/
   /*
   if (socket.isOpen()) {
       qInfo() << "inside send request" << Qt::endl;

       // Define your AES parameters
       QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef"); // 32 bytes key for AES-256
       QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210");   // 16 bytes IV for AES

       QByteArray rawData = data.toUtf8();
       qInfo() << "rawData: " << rawData << Qt::endl;

       // Encrypt the data
       QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC, QAESEncryption::PKCS7);
       QByteArray encryptedData = encryption.encode(rawData, key, iv);

       qInfo() << "encryptedData: " << encryptedData << Qt::endl;

       // Check if the encryption produced any data
       if (encryptedData.isEmpty()) {
           qWarning() << "Encryption failed, no data produced.";
           return;
       }

       socket.write(encryptedData);
       qInfo() << "send encrypted request" << Qt::endl;
   }*/


   /********************/
   if (socket.isOpen())
   {
       qInfo() << "Inside send request" << Qt::endl;

       // Define your AES parameters
       QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"); // 64 hex characters = 32 bytes
       QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210"); // 32 hex characters = 16 bytes

        QByteArray rawData = data.toUtf8();
       // qInfo() << "Raw data" << rawData << Qt::endl;
       /**************************************************/
       // Generate hash-based signature using a secret key
       QByteArray secretKey = "IMT_Secret_key1234"; // Example secret key for hashing
       QByteArray hashSignature = QCryptographicHash::hash(rawData + secretKey, QCryptographicHash::Sha256).toHex();

       // Combine the data with the hash signature
       QString combinedData = data + "|" + QString(hashSignature);
       QByteArray combinedDataBytes = combinedData.toUtf8();
       /***************************************************/



       // Encrypt the data
       QByteArray encryptedData = QAESEncryption::Crypt(
           QAESEncryption::AES_256, // AES level (AES_128, AES_192, or AES_256)
           QAESEncryption::CBC,     // Mode (ECB, CBC, CFB, OFB)
        /*modefied*/   combinedDataBytes,                 // Raw data to encrypt
           key,                     // Encryption key
           iv,                      // Initialization vector
           QAESEncryption::PKCS7    // Padding (ZERO, PKCS7, ISO)
           );

       if (encryptedData.isEmpty())
       {
           qWarning() << "Encryption failed, no data produced.";
           return;
       }

       // qInfo() << "Encrypted data" << encryptedData << Qt::endl;
       socket.write(encryptedData);
       //qInfo() << "Sent encrypted request" << Qt::endl;
   }
}



void MyClient::onConnection()
{
    emit Connection();
}

void MyClient::onDisconnected()
{
    emit Disconnected();
}

void MyClient::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    emit ErrorOccurred(socketError);
}

void MyClient::onStateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    emit StateChanged(socketState);
}

// void MyClient::onReadyRead()
// {
//     QByteArray byteArray = socket.readAll();
//     QString data = QString(byteArray);
//     qInfo()<<"received data from server=>"<<data<<Qt::endl;
//     emit ReadyRead(data);
// }


void MyClient::onReadyRead()
{
    QByteArray data = socket.readAll();
    qInfo()<<"received==>"<<QString(data)<<Qt::endl;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    // if (!jsonDoc.isNull() && jsonDoc.isObject())
    // {
        QJsonObject response = jsonDoc.object();
    //     if (response["status"].toString() == "success")
    //     {
    //         QMessageBox::information(nullptr, "success", "Login successful.");
    //        // handleLoginResponse(response);
    //     }
    //     else
    //     {
    //         QMessageBox::critical(nullptr, "Error", "Login failed: Invalid username or password.");

    //     }
    // }

    emit ReadyRead(response);
}


/*******************************************************/
void MyClient::sendRequest(const QJsonObject &request)
{
    QJsonDocument doc(request);
    QByteArray data = doc.toJson();

    // Encrypt the data here if necessary
    if(socket.isOpen())
    {
        qInfo()<<"opened\n";
        socket.write(data);
        socket.flush();
    }
   qInfo()<<"closed\n";
}


void MyClient::sendEmail(const QString &to, const QString &subject, const QString &body)
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QUrl url("https://nadamohamed2001.pythonanywhere.com/receive_email");
    QNetworkRequest request(url);

    QUrlQuery query;
    query.addQueryItem("to", to);
    query.addQueryItem("subject", subject);
    query.addQueryItem("body", body);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

   // QNetworkReply *reply = manager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());
    QNetworkReply *reply = manager->get(request, query.toString(QUrl::FullyEncoded).toUtf8());

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Email data sent successfully!";
        } else {
            qDebug() << "Error sending email data:" << reply->errorString();
        }
        reply->deleteLater();
    });
}





/*
void MyClient::sendEmail(const QString &to, const QString &subject, const QString &body)
{




    QProcess process; // Create a QProcess object to run external processes

    // Path to your batch script
    QString batchFilePath = "D:\\ITIDA_Scholarship\\Final project\\sendEmail.bat"; // Specify the path to the batch file for sending emails

    // Prepare arguments
    QStringList arguments;
    arguments << to << subject << body; // Prepare arguments for the batch script (recipient email, subject, body)

    // Start the batch script with arguments
    process.start(batchFilePath, arguments); // Start the batch script with specified arguments
    if (!process.waitForFinished())
    {
        //logger.logMessage(QString("Failed to run batch script: %1").arg(process.errorString())); // Log an error if the batch script fails to execute
        qDebug() <<QString("Failed to run batch script: %1").arg(process.errorString());
        return;
    }

    // Read and display the output or err
    QString output = process.readAllStandardOutput();
    // QString error = process.readAllStandardError();
    QString error = process.readAllStandardError(); // Read standard error output from the process
    if (!error.isEmpty())
    {
        qDebug() <<QString("Error sending email: %1").arg(error); // Log an error if there is any error output from the process
    }
    else
    {

        qDebug() << "successful sending email.........."<<Qt::endl;
        qDebug() << "Output:" << output;
    }
}*/

/*

QString MyClient::encryptData(const QString &data)
{
    QCA::Initializer init;

    // Generate AES key and initialization vector
    QCA::SymmetricKey key = QCA::SymmetricKey::generate(Qt::BlockSize);

    QCA::InitializationVector iv = QCA::InitializationVector::generate(key.cipherMode());

    // Create AES cipher
    QCA::Cipher cipher(key, QCA::Cipher::AES128, QCA::Cipher::CBC, QCA::Cipher::PKCS7Padding);

    // Encrypt the data
    QCA::SecureArray encrypted = cipher.encrypt(data.toUtf8(), iv);

    // Return base64 encoded encrypted data
    return QString(encrypted.toByteArray().toBase64());
}
*/

