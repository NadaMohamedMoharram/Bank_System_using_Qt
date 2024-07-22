#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>             // Base class for all Qt objects
#include <QTcpSocket>          // Provides TCP socket functionality
#include <QString>            // Provides string handling
#include <QJsonArray>         // For handling JSON arrays
#include <QJsonObject>        // For handling JSON objects
#include <QJsonDocument>      // For handling JSON documents
#include <QFile>              // For file operations
#include <QMessageBox>        // For displaying message boxes
#include "qaesencryption.h"   // Custom header for encryption
#include <QNetworkAccessManager> // Manages network access
#include <QNetworkRequest>    // Represents a network request
#include <QNetworkReply>      // Represents the reply to a network request
#include <QUrl>               // For URL handling
#include <QUrlQuery>          // For URL query handling
#include <QDebug>             // For debugging output
#include <QBuffer>            // For buffering data

class MyClient : public QObject
{
    Q_OBJECT // Macro for enabling signals and slots mechanism in Qt

public:
    explicit MyClient(QObject *parent = nullptr); // Constructor with optional parent
    void ConnectToDevice(QString ip, qint32 port); // Connects to the server using IP and port
    void Disconnect(); // Disconnects from the server
    void WriteData(QString data); // Sends data to the server
    void sendRequest(const QJsonObject &request); // Sends a JSON request to the server
    void sendEmail(const QString &to, const QString &subject, const QString &body); // Sends an email

signals:
    void Connection(); // Signal emitted when connection is established
    void Disconnected(); // Signal emitted when disconnected from the server
    void ErrorOccurred(QAbstractSocket::SocketError socketError); // Signal emitted on socket error
    void StateChanged(QAbstractSocket::SocketState socketState); // Signal emitted when socket state changes
    void ReadyRead(const QJsonObject &request); // Signal emitted when data is ready to read

private slots:
    void onConnection(); // Slot to handle connection established
    void onDisconnected(); // Slot to handle disconnection
    void onErrorOccurred(QAbstractSocket::SocketError socketError); // Slot to handle socket errors
    void onStateChanged(QAbstractSocket::SocketState socketState); // Slot to handle state changes
    void onReadyRead(); // Slot to handle data ready to read

private:
    QString ip; // IP address of the server
    qint32 port; // Port number of the server
    QTcpSocket socket; // TCP socket for communication
};

#endif // MYCLIENT_H
