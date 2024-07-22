#ifndef DATABASE_H
#define DATABASE_H

// Include guards to prevent multiple inclusions of this header file
#include <QObject>            // Includes the base class for all Qt objects
#include <QJsonObject>        // Includes the class for JSON objects
#include <QJsonArray>         // Includes the class for JSON arrays
#include <QJsonDocument>      // Includes the class for JSON document handling
#include <QFile>              // Includes the class for file handling
#include <QVector>            // Includes the class for vector container
#include <QDebug>             // Includes the class for debugging output
#include <QRandomGenerator>
// Declaration of the DataBase class, inheriting from QObject
class DataBase : public QObject
{
    Q_OBJECT // Macro to enable Qt's meta-object system for signals and slots

public:
    // Constructor for the DataBase class
    explicit DataBase(QObject *parent = nullptr);

    // Function to verify user credentials
    QString verifyCredentials(const QString& username, const QString& password);

    // Function to get the account number associated with a username
    QString getAccountNumber(const QString& username);

    // Function to get the balance of an account
    int getAccountBalance(const QString& accountNumber);

    // Function to get the transaction history of an account
    QJsonArray getTransactionHistory(const QString& accountNumber, int count);

    // Function to get the email associated with an account number
    QString getAccountEmail(const QString &accountNumber);

    // Function to make a transaction on an account
    bool makeTransaction(const QString& accountNumber, int transactionAmount);

    // Function to transfer an amount from one account to another
    bool transferAmount(const QString& fromAccountNumber, const QString& toAccountNumber, int transferAmount);

    // Function to save the database to a file
    void saveDataBase();

    // Function to view the entire bank database
    QJsonArray viewBankDatabase();

    // Function to create a new user with provided data
    bool createNewUser(const QJsonObject &userData);

    // Function to delete a user by their account number
    bool deleteUser(const QString& accountNumber);

    // Function to update user information
    bool updateUser(const QString& accountNumber, const QJsonObject &newData);

    // Function to  generate random account numbers
    QString generateRandomAccountNumber(int length = 9);
private:
    // Path to the JSON file that stores the database
    QString FilePath = "D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\LoginDB.json";

    // Vector to hold the JSON objects representing the database
    QVector<QJsonObject> jsonDataBase;

    // Function to initialize the database from the file
    void initDataBase();
};

#endif // DATABASE_H
