#ifndef ADMIN_CLASS_H // Include guard to prevent multiple inclusions of this header file
#define ADMIN_CLASS_H

#include <QObject>  // Include the base class for all Qt objects
#include "DataBase.h"  // Include the header file for the DataBase class

class Admin_Class : public QObject  // Definition of Admin_Class which inherits from QObject
{
    Q_OBJECT  // Macro to enable the use of signals and slots

public:
    explicit Admin_Class(QObject *parent = nullptr);  // Constructor declaration with an optional parent QObject
    void GetAccountNumber(QString username);  // Method to get the account number for a given username
    void GetBalance(const QString& accountNumber);  // Method to get the balance for a given account number
    void GetTransactionHistory(const QString &accountNumber, int count);  // Method to get the transaction history for a given account number and count
    void ViewBankDatabaseRequest();  // Method to request the entire bank database
    void CreateNewUserRequest(const QJsonObject &userData);  // Method to request the creation of a new user with given data
    void DeleteUserRequest(const QString& accountNumber);  // Method to request the deletion of a user by account number
    void UpdateUserRequest(const QString& accountNumber, const QJsonObject &userData);  // Method to request the update of user data for a given account number

signals:
    void sendMessageSignal(const QString &message);  // Signal to send a message
    void sendEmailSignal(const QString &to, const QString &subject, const QString &body);  // Signal to send an email

private:
    DataBase db;  // Member object of DataBase class used to interact with the database
};

#endif // ADMIN_CLASS_H  // End of include guard
