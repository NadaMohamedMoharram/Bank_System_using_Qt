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

void Admin_Class::GetTransactionHistory(const QString &accountNumber, int count)
{
    QJsonArray transactions = db.getTransactionHistory(accountNumber, count);

    QJsonObject response;
    response["status"] = "transaction_history_response";
    response["account_number"] = accountNumber;
    response["transactions"] = transactions;
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

void Admin_Class::CreateNewUserRequest(const QJsonObject &userData)
{

    QJsonObject response;
    bool CreateUserResult = db.createNewUser(userData);

    response["status"] = "CreateUser_response";
    if (CreateUserResult==true)
        response["NewUser_Result"] = "Create new user successful";
    else
        response["NewUser_Result"] = "Create new user failed. username or acount number is already used";


    emit sendMessageSignal(QJsonDocument(response).toJson());
}

void Admin_Class::DeleteUserRequest(const QString &accountNumber)
{

    QJsonObject response;
    bool DeleteUserResult = db.deleteUser(accountNumber);

    response["status"] = "DeleteUser_response";
    if (DeleteUserResult==true)
        response["DeleteUser_Result"] = "Delete user successful";
    else
        response["DeleteUser_Result"] = "Delete user failed.";


    emit sendMessageSignal(QJsonDocument(response).toJson());
}

void Admin_Class::UpdateUserRequest(const QString &accountNumber, const QJsonObject &userData)
{

    QJsonObject response;
    bool UpdateUserResult = db.updateUser(accountNumber , userData);

    response["status"] = "UpdateUser_response";
    if (UpdateUserResult==true)
        response["UpdateUser_Result"] = "Update user successful";
    else
        response["UpdateUser_Result"] = "Update user failed.";


    emit sendMessageSignal(QJsonDocument(response).toJson());
}
