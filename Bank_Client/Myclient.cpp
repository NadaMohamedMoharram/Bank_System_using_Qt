#include "MyClient.h"           // Include the header file for MyClient
#include <QProcess>             // Provides access to processes
#include <QCryptographicHash>   // Provides hashing functions

// Constructor for MyClient class
MyClient::MyClient(QObject *parent)
    : QObject{parent} // Initialize the base class with the parent
{
    // Connect various signals from QTcpSocket to corresponding slots
    connect(&socket, &QTcpSocket::connected, this, &MyClient::onConnection);
    connect(&socket, &QTcpSocket::disconnected, this, &MyClient::onDisconnected);
    connect(&socket, &QTcpSocket::errorOccurred, this, &MyClient::onErrorOccurred);
    connect(&socket, &QTcpSocket::stateChanged, this, &MyClient::onStateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
}

// Connect to a TCP server using IP and port
void MyClient::ConnectToDevice(QString ip, qint32 port)
{
    // Check if the socket is already open
    if (socket.isOpen())
    {
        // If already connected to the same IP and port, return
        if ((this->ip == ip) && (this->port == port))
        {
            return;
        }
        else
        {
            // If different IP or port, close the socket and reconnect
            socket.close();
            this->port = port;
            this->ip = ip;
            socket.connectToHost(this->ip, this->port);
            qInfo() << "Connecting to server.......";
        }
    }
    else
    {
        // If not connected, set IP and port, and connect
        this->port = port;
        this->ip = ip;
        socket.connectToHost(this->ip, this->port);
        qInfo() << "Connecting to server.......";
    }
}

// Disconnect from the TCP server
void MyClient::Disconnect()
{
    if (socket.isOpen())
    {
        socket.close();
    }
}

// Write data to the TCP server
void MyClient::WriteData(QString data)
{
    if (socket.isOpen())
    {
        qInfo() << "Inside send request" << Qt::endl;

        // Define AES encryption parameters
        QByteArray key = QByteArray::fromHex("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"); // 32 bytes
        QByteArray iv = QByteArray::fromHex("abcdef9876543210abcdef9876543210"); // 16 bytes

        QByteArray rawData = data.toUtf8();

        // Generate a hash-based signature using a secret key
        QByteArray secretKey = "IMT_Secret_key1234"; // Example secret key for hashing
        QByteArray hashSignature = QCryptographicHash::hash(rawData + secretKey, QCryptographicHash::Sha256).toHex();

        // Combine the original data with the hash signature
        QString combinedData = data + "|" + QString(hashSignature);
        QByteArray combinedDataBytes = combinedData.toUtf8();

        // Encrypt the combined data
        QByteArray encryptedData = QAESEncryption::Crypt(
            QAESEncryption::AES_256, // Encryption level
            QAESEncryption::CBC,     // Mode of operation
            combinedDataBytes,       // Data to encrypt
            key,                     // Encryption key
            iv,                      // Initialization vector
            QAESEncryption::PKCS7    // Padding
            );

        if (encryptedData.isEmpty())
        {
            qWarning() << "Encryption failed, no data produced.";
            return;
        }

        // Write encrypted data to the socket
        socket.write(encryptedData);
    }
}

// Slot for handling successful connection
void MyClient::onConnection()
{
    emit Connection();
}

// Slot for handling disconnection
void MyClient::onDisconnected()
{
    emit Disconnected();
}

// Slot for handling socket errors
void MyClient::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    emit ErrorOccurred(socketError);
}

// Slot for handling state changes of the socket
void MyClient::onStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    emit StateChanged(socketState);
}

// Slot for handling incoming data
void MyClient::onReadyRead()
{
    QByteArray data = socket.readAll(); // Read all available data from the socket
    qInfo() << "Received ==>" << QString(data) << Qt::endl;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data); // Parse JSON data
    QJsonObject response = jsonDoc.object(); // Convert JSON document to object
    emit ReadyRead(response);
}


// Send a JSON request to the server
void MyClient::sendRequest(const QJsonObject &request)
{
    QJsonDocument doc(request); // Convert JSON object to document
    QByteArray data = doc.toJson(); // Convert document to bytes

    if (socket.isOpen())
    {
        qInfo() << "Socket is open";
        socket.write(data); // Write data to socket
        socket.flush(); // Ensure all data is sent
    }
    qInfo() << "Socket closed";
}

// Send an email using a web service
void MyClient::sendEmail(const QString &to, const QString &subject, const QString &body)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this); // Create network access manager

    QUrl url("https://nadamohamed2001.pythonanywhere.com/receive_email"); // URL of the email service
    QNetworkRequest request(url); // Create network request

    QUrlQuery query; // Query parameters for the request
    query.addQueryItem("to", to);
    query.addQueryItem("subject", subject);
    query.addQueryItem("body", body);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded"); // Set content type

    // Send a GET request with query parameters
    QNetworkReply *reply = manager->get(request, query.toString(QUrl::FullyEncoded).toUtf8());

    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Email data sent successfully!";
        } else {
            qDebug() << "Error sending email data:" << reply->errorString();
        }
        reply->deleteLater(); // Clean up reply object
    });
}
