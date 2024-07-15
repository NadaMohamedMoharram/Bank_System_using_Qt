#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QFile>
#include<QVector>
#include<QDebug>

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    void addObject(QString name,qint32 age);
    void updateObject(qint32 id,QString name,qint32 age);
    void deleteObject(qint32 id);
    void showDataBase();
    QString verifyCredentials(const QString& username, const QString& password);
    QString getAccountNumber(const QString& username);
    /**/int getAccountBalance(const QString& accountNumber);
    QJsonArray getTransactionHistory(const QString& accountNumber, int count);
    bool makeTransaction( const QString& accountNumber, int transactionAmount);
    bool transferAmount(const QString& fromAccountNumber, const QString& toAccountNumber, int transferAmount);
    void saveDataBase();
    QJsonArray viewBankDatabase();
    bool createNewUser(const QJsonObject &userData);
    bool deleteUser( const QString& accountNumber);
    bool updateUser( const QString& accountNumber , const QJsonObject &newData);
    //  QString GetUserAuthority(const QString & username);
private:
    QString FilePath="D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\LoginDB.json";
    QVector<QJsonObject> jsonDataBase;
    void initDataBase();
};

#endif // DATABASE_H
