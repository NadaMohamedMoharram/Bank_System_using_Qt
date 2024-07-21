#include "Admin_Class.h"  // Include the header file for the Admin_Class

Admin_Class::Admin_Class(QObject *parent)
    : QObject{parent}  // Constructor for Admin_Class, initializes the QObject with an optional parent
{}

void Admin_Class::GetAccountNumber(QString username)
{
    QJsonObject response;  // Create a QJsonObject to build the response
    QString accountNumber = db.getAccountNumber(username);  // Get the account number from the database using the provided username
    response["status"] = "success_GetAccountNumber";  // Set the status in the response
    response["account_number"] = accountNumber;  // Add the account number to the response
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}

void Admin_Class::GetBalance(const QString &accountNumber)
{
    int balance = db.getAccountBalance(accountNumber);  // Get the balance from the database using the provided account number

    QJsonObject response;  // Create a QJsonObject to build the response
    response["status"] = "account_balance_response";  // Set the status in the response
    response["account_number"] = accountNumber;  // Add the account number to the response
    response["balance"] = balance;  // Add the balance to the response
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}

void Admin_Class::GetTransactionHistory(const QString &accountNumber, int count)
{
    QJsonArray transactions = db.getTransactionHistory(accountNumber, count);  // Get the transaction history from the database

    QJsonObject response;  // Create a QJsonObject to build the response
    response["status"] = "transaction_history_response";  // Set the status in the response
    response["account_number"] = accountNumber;  // Add the account number to the response
    response["transactions"] = transactions;  // Add the transactions array to the response
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}

void Admin_Class::ViewBankDatabaseRequest()
{
    QJsonObject response;  // Create a QJsonObject to build the response
    QJsonArray Data = db.viewBankDatabase();  // Get the entire bank database as a QJsonArray
    response["status"] = "ViewBankDatabase_response";  // Set the status in the response
    response["data"] = Data;  // Add the database data to the response
    // sendMessage(QJsonDocument(response).toJson());  // Commented out old way of sending messages
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}

void Admin_Class::CreateNewUserRequest(const QJsonObject &userData)
{
    QJsonObject response;  // Create a QJsonObject to build the response
    bool CreateUserResult = db.createNewUser(userData);  // Attempt to create a new user in the database with the provided data

    response["status"] = "CreateUser_response";  // Set the status in the response
    if (CreateUserResult == true)
        response["NewUser_Result"] = "Create new user successful";  // Indicate success if user creation was successful
    else
        response["NewUser_Result"] = "Create new user failed. username or account number is already used";  // Indicate failure if user creation failed

    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}

void Admin_Class::DeleteUserRequest(const QString &accountNumber)
{
    QJsonObject response;  // Create a QJsonObject to build the response
    bool DeleteUserResult = db.deleteUser(accountNumber);  // Attempt to delete the user with the provided account number

    response["status"] = "DeleteUser_response";  // Set the status in the response
    if (DeleteUserResult == true)
        response["DeleteUser_Result"] = "Delete user successful";  // Indicate success if user deletion was successful
    else
        response["DeleteUser_Result"] = "Delete user failed.";  // Indicate failure if user deletion failed

    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}

void Admin_Class::UpdateUserRequest(const QString &accountNumber, const QJsonObject &userData)
{
    QJsonObject response;  // Create a QJsonObject to build the response
    bool UpdateUserResult = db.updateUser(accountNumber, userData);  // Attempt to update the user data for the provided account number

    response["status"] = "UpdateUser_response";  // Set the status in the response
    if (UpdateUserResult == true)
        response["UpdateUser_Result"] = "Update user successful";  // Indicate success if user update was successful
    else
        response["UpdateUser_Result"] = "Update user failed.";  // Indicate failure if user update failed

    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON string using the sendMessageSignal
}
