#ifndef USER_CLASS_H
#define USER_CLASS_H

#include <QObject>  // Include QObject for the base class
#include "DataBase.h"  // Include DataBase header for database operations

class User_Class : public QObject
{
    Q_OBJECT  // Enable Qt's signal and slot mechanism
public:
    explicit User_Class(QObject *parent = nullptr);  // Constructor with optional parent parameter
    void GetAccountNumber(QString username);  // Method to get account number by username
    void GetBalance(const QString& accountNumber);  // Method to get balance by account number
    void GetTransactionHistory(const QString& accountNumber, int count);  // Method to get transaction history by account number and count
    void MakeTransactionRequest(const QString& accountNumber, int transactionAmount, const QString& transactionType);  // Method to make a transaction request
    void TransferAmountRequest(const QString& fromAccountNumber, const QString& toAccountNumber, int transferAmount);  // Method to request a transfer of amount between accounts

signals:
    void sendMessageSignal(const QString &message);  // Signal to send a message
    void sendEmailSignal(const QString &to, const QString &subject, const QString &body);  // Signal to send an email

private:
    DataBase db;  // Instance of DataBase for handling database operations
};

#endif // USER_CLASS_H
