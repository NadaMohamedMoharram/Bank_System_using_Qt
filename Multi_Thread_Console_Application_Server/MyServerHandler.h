#ifndef MYSERVERHANDLER_H  // Include guard to prevent multiple inclusions of this header file
#define MYSERVERHANDLER_H

#include <QObject>  // Include QObject class for signals and slots
#include <QThread>  // Include QThread class for thread handling
#include <QTcpSocket>  // Include QTcpSocket class for TCP socket communication
#include <QDebug>  // Include QDebug class for debugging messages
#include "DataBase.h"  // Include DataBase class header for database operations
#include "User_Class.h"  // Include User_Class header for user operations
#include "Admin_Class.h"  // Include Admin_Class header for admin operations

#include <QFile>  // Include QFile class for file handling
#include <QTextStream>  // Include QTextStream class for text input/output

#include <QNetworkAccessManager>  // Include QNetworkAccessManager class for network access
#include <QNetworkReply>  // Include QNetworkReply class for network replies
#include <QNetworkRequest>  // Include QNetworkRequest class for network requests
#include <QProcess>  // Include QProcess class for running processes

#include <QJsonArray>  // Include QJsonArray class for handling JSON arrays
#include <QJsonObject>  // Include QJsonObject class for handling JSON objects
#include <QJsonDocument>  // Include QJsonDocument class for handling JSON documents


#include <QNetworkAccessManager>  // Include QNetworkAccessManager class (redundant inclusion)
#include <QNetworkRequest>  // Include QNetworkRequest class (redundant inclusion)
#include <QNetworkReply>  // Include QNetworkReply class (redundant inclusion)
#include <QUrl>  // Include QUrl class for URL handling
#include <QUrlQuery>  // Include QUrlQuery class for URL query handling
#include <QDebug>  // Include QDebug class for debugging messages (redundant inclusion)

#include "qaesencryption.h"  // Include QAES encryption class header for encryption operations

class MyServerHandler : public QThread  // Define MyServerHandler class, inheriting from QThread
{
    Q_OBJECT  // Macro to enable signal and slot mechanisms

public:
    explicit MyServerHandler(qint32 ID, QObject *parent = nullptr);  // Constructor with an ID and optional parent object
    QJsonObject ConvertToJsonObj(QString Message);  // Method to convert a QString message to QJsonObject
    void OnLogin(QString username, QString password);  // Method to handle login operation
    void sendEmail(const QString &to, const QString &subject, const QString &body);  // Method to send an email
    void logRequest(const QString &request);  // Method to log a request

signals:  // Section for defining signals (none in this case)

private:
    qint32 ID;  // Private member to store the connection ID
    QTcpSocket* Socket;  // Private member to handle the TCP socket
    DataBase Data_Base;  // Private member to interact with the database
    Admin_Class adminFacade;  // Private member to handle admin operations
    User_Class userFacade;  // Private member to handle user operations

    // QThread interface
protected:
    void run() override;  // Override run method from QThread for thread execution

public slots:  // Section for defining slots
    void onReadyRead();  // Slot to handle ready-read events from the socket
    void onDisconnected();  // Slot to handle disconnection events from the socket
    void sendMessage(QString Message);  // Slot to send a message through the socket
    void Operation(QString Operation);  // Slot to perform operations based on the operation string
};

#endif // MYSERVERHANDLER_H  // End of include guard
