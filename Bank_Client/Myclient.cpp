#include "MyClient.h"
#include<QProcess>
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
    if(socket.isOpen())
    {
        qInfo()<<"inside send request"<<Qt::endl;
        // Define your AES parameters
        // Define your AES parameters
        const QByteArray key = "1234567890123456"; // Example: 32 bytes key for AES-256
        const QByteArray iv = "1234567890123456";   // Example: 16 bytes IV for AES
        QByteArray rawData = data.toUtf8();

        // Encrypt the data
        QByteArray encryptedData = QAESEncryption::Crypt(
            QAESEncryption::AES_256, // AES level (AES_128, AES_192, or AES_256)
            QAESEncryption::CBC,     // Mode (ECB, CBC, CFB, OFB)
            rawData,                 // Raw data to encrypt
            key,                     // Encryption key
            iv,                      // Initialization vector
            QAESEncryption::PKCS7    // Padding (ZERO, PKCS7, ISO)
            );
         QString encryptedDataNew = QString(encryptedData);

         socket.write(encryptedDataNew.toUtf8());

       // socket.write(data.toUtf8());
      //  socket.write(encryptedData);
        qInfo()<<" send encrypted request"<<Qt::endl;

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




    QProcess process; // Create a QProcess object to run external processes

    // Path to your batch script
    QString batchFilePath = "D:\\ITIDA_Scholarship\\Final project\\send_email.bat"; // Specify the path to the batch file for sending emails

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
}

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

