#ifndef MYSERVERHANDLER_H
#define MYSERVERHANDLER_H

#include <QObject>
#include<QThread>
#include<QTcpSocket>
#include<QDebug>
#include"DataBase.h"
#include"User_Class.h"
#include"Admin_Class.h"



#include <QFile>
#include <QTextStream>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>


#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

/********/
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
/*************/

#include"qaesencryption.h"
//class database--->databaseinit  vector from Qjsonobject

class MyServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit MyServerHandler(qint32 ID,QObject *parent = nullptr);
    QJsonObject ConvertToJsonObj(QString Message);

 void OnLogin(QString username , QString password);
 void GetAccountNumber(QString username);
 void GetBalance(const QString& accountNumber);
 void GetTransactionHistory(const QString& accountNumber, int count);
 void MakeTransactionRequest(const QString& accountNumber, int transactionAmount ,const QString& transactionType);
 void TransferAmountRequest (const QString& fromAccountNumber, const QString& toAccountNumber, int transferAmount);
 void ViewBankDatabaseRequest();
 void CreateNewUserRequest(const QJsonObject &userData);
 void DeleteUserRequest(const QString& accountNumber);
 void UpdateUserRequest (const QString& accountNumber , const QJsonObject &userData);
 void sendEmail(const QString &to, const QString &subject, const QString &body) ;
 void logRequest(const QString &request);
 signals:

private:
    qint32 ID;
    QTcpSocket* Socket;
    DataBase Data_Base;
    Admin_Class adminFacade;
    User_Class userFacade;
\

    // QThread interface
protected:
    void run() override;

public slots:
    void onReadyRead();
    void onDisconnected();
    void sendMessage(QString Message);
    void Operation(QString Operation);

public slots:
    void handleAdminMessage(const QString &message);  // Slot to handle admin messages

};

#endif // MYSERVERHANDLER_H
