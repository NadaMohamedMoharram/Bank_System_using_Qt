#ifndef USER_CLASS_H
#define USER_CLASS_H

#include <QObject>
//#include"MyServerHandler.h"
#include"DataBase.h"

class User_Class : public QObject
{
    Q_OBJECT
public:
    explicit User_Class(QObject *parent = nullptr);
    void GetAccountNumber(QString username);
    void GetBalance(const QString& accountNumber);
    void GetTransactionHistory(const QString& accountNumber, int count);
    void MakeTransactionRequest(const QString& accountNumber, int transactionAmount ,const QString& transactionType);
    void TransferAmountRequest (const QString& fromAccountNumber, const QString& toAccountNumber, int transferAmount);

signals:
    void sendMessageSignal(const QString &message);  // Signal to send a message
    void sendEmailSignal(const QString &to, const QString &subject, const QString &body);

private:
    //MyServerHandler* handler;
    DataBase db;
};

#endif // USER_CLASS_H
