#ifndef MYSERVERHANDLER_H
#define MYSERVERHANDLER_H

#include <QObject>
#include<QThread>
#include<QTcpSocket>
#include<QDebug>
#include"DataBase.h"

//class database--->databaseinit  vector from Qjsonobject

class MyServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit MyServerHandler(qint32 ID,QObject *parent = nullptr);
    QJsonObject ConvertToJsonObj(QString Message);

   /***********/ void OnLogin(QString username , QString password);
 void GetAccountNumber(QString username);
 void GetBalance(const QString& accountNumber);
 void GetTransactionHistory(const QString& accountNumber, int count);
 void MakeTransactionRequest(const QString& accountNumber, int transactionAmount ,const QString& transactionType);
 void TransferAmountRequest (const QString& fromAccountNumber, const QString& toAccountNumber, int transferAmount);
signals:

private:
    qint32 ID;
    QTcpSocket* Socket;
    DataBase Data_Base;
    // QThread interface
protected:
    void run() override;

public slots:
    void onReadyRead();
    void onDisconnected();
    void sendMessage(QString Message);
    void Operation(QString Operation);
};

#endif // MYSERVERHANDLER_H
