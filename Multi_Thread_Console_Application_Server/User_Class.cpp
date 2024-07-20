#include "User_Class.h"

User_Class::User_Class(QObject *parent)
    : QObject{parent}
{}

void User_Class::GetAccountNumber(QString username)
{
    QJsonObject response;
    qInfo()<<"inside user get account"<<Qt::endl;

    QString accountNumber = db.getAccountNumber(username);
    response["status"] = "success_GetAccountNumber";
    response["account_number"] = accountNumber;
    emit sendMessageSignal(QJsonDocument(response).toJson());
}




 void User_Class::GetBalance(const QString &accountNumber)
 {
     int balance = db.getAccountBalance(accountNumber);

     QJsonObject response;
     response["status"] = "account_balance_response";
     response["account_number"] = accountNumber;
     response["balance"] = balance;
     emit sendMessageSignal(QJsonDocument(response).toJson());
 }

// void User_Class::GetTransactionHistory(const QString &accountNumber, int count)
// {

// }

// void User_Class::MakeTransactionRequest(const QString &accountNumber, int transactionAmount, const QString &transactionType)
// {

// }

// void User_Class::TransferAmountRequest(const QString &fromAccountNumber, const QString &toAccountNumber, int transferAmount)
// {

// }

