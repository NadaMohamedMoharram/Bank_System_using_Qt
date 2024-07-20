#include "Admin_Class.h"

Admin_Class::Admin_Class(QObject *parent)
    : QObject{parent}
{}

void Admin_Class::GetAccountNumber(QString username)
{
    QJsonObject response;
    QString accountNumber = db.getAccountNumber(username);
    response["status"] = "success_GetAccountNumber";
    response["account_number"] = accountNumber;
    emit sendMessageSignal(QJsonDocument(response).toJson());

}

void Admin_Class::GetBalance(const QString &accountNumber)
{

    int balance = db.getAccountBalance(accountNumber);

    QJsonObject response;
    response["status"] = "account_balance_response";
    response["account_number"] = accountNumber;
    response["balance"] = balance;
    emit sendMessageSignal(QJsonDocument(response).toJson());
}
void Admin_Class::ViewBankDatabaseRequest()
{

    QJsonObject response;
    QJsonArray Data=db.viewBankDatabase();
    response["status"] = "ViewBankDatabase_response";
    response["data"]=Data;
   // sendMessage(QJsonDocument(response).toJson());
     emit sendMessageSignal(QJsonDocument(response).toJson());

}
