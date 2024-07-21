#ifndef ADMIN_CLASS_H
#define ADMIN_CLASS_H

#include <QObject>
#include"DataBase.h"

class Admin_Class : public QObject
{
    Q_OBJECT
public:
    explicit Admin_Class(QObject *parent = nullptr);
    void GetAccountNumber(QString username);
    void GetBalance(const QString& accountNumber);
    void GetTransactionHistory(const QString &accountNumber, int count);
    void ViewBankDatabaseRequest();
    void CreateNewUserRequest(const QJsonObject &userData);
    void DeleteUserRequest(const QString& accountNumber);
    void UpdateUserRequest (const QString& accountNumber , const QJsonObject &userData);

signals:
    void sendMessageSignal(const QString &message);  // Signal to send a message
    void sendEmailSignal(const QString &to, const QString &subject, const QString &body);

private:
       DataBase db;
};

#endif // ADMIN_CLASS_H
