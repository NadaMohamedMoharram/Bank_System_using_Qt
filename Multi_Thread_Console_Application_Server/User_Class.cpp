#include "User_Class.h"  // Include the header file for User_Class

User_Class::User_Class(QObject *parent)
    : QObject{parent}  // Initialize the base QObject class with an optional parent parameter
{}

void User_Class::GetAccountNumber(QString username)
{
    QJsonObject response;  // Create a QJsonObject to store the response data
    qInfo()<<"inside user get account"<<Qt::endl;  // Log information for debugging

    QString accountNumber = db.getAccountNumber(username);  // Retrieve the account number from the database
    response["status"] = "success_GetAccountNumber";  // Set status in response
    response["account_number"] = accountNumber;  // Include the account number in the response
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON message
}

void User_Class::GetBalance(const QString &accountNumber)
{
    int balance = db.getAccountBalance(accountNumber);  // Retrieve the balance for the specified account number

    QJsonObject response;  // Create a QJsonObject to store the response data
    response["status"] = "account_balance_response";  // Set status in response
    response["account_number"] = accountNumber;  // Include the account number in the response
    response["balance"] = balance;  // Include the balance in the response
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON message
}

void User_Class::GetTransactionHistory(const QString &accountNumber, int count)
{
    QJsonArray transactions = db.getTransactionHistory(accountNumber, count);  // Retrieve transaction history from the database

    QJsonObject response;  // Create a QJsonObject to store the response data
    response["status"] = "transaction_history_response";  // Set status in response
    response["account_number"] = accountNumber;  // Include the account number in the response
    response["transactions"] = transactions;  // Include the transaction history in the response
    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON message
}

void User_Class::MakeTransactionRequest(const QString &accountNumber, int transactionAmount, const QString &transactionType)
{
    QJsonObject response;  // Create a QJsonObject to store the response data
    QString emailBody;  // String to hold the email body
    int ActualtransactionAmount = transactionAmount;  // Store the original transaction amount

    if (transactionType == "Withdrow")  // Check if the transaction type is "Withdrow"
    {
        transactionAmount *= -1;  // Negate the transaction amount for withdrawal
    }

    bool transactionResult = db.makeTransaction(accountNumber, transactionAmount);  // Perform the transaction in the database
    response["status"] = "transaction_amount_response";  // Set status in response
    if (transactionResult == true)  // Check if the transaction was successful
    {
        response["transaction_Result"] = "Transaction successful";  // Set success message in response
        emailBody = QString("Dear Client,\nWe want to inform you that your transaction request succeeded.\nYou %1 %2 L.E\n\nBest Regards,\nIMT_ITIDA Bank")
                        .arg(transactionType)  // Include transaction type in email body
                        .arg(QString::number(ActualtransactionAmount));  // Include transaction amount in email body
    }
    else
    {
        response["transaction_Result"] = "Transaction failed";  // Set failure message in response
        emailBody = QString("Dear Client,\nWe regret to inform you that your transaction request is failed.\nBest Regards,\nIMT_ITIDA Bank");  // Failure email body
    }

    QString to =  db.getAccountEmail(accountNumber);  // Email address of the recipient (placeholder)
    QString subject = "Transaction Notification";  // Subject of the email

    emit sendEmailSignal(to, subject, emailBody);  // Emit the email signal with the recipient, subject, and body

    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON message
}

void User_Class::TransferAmountRequest(const QString &fromAccountNumber, const QString &toAccountNumber, int transferAmount)
{
    QJsonObject response;  // Create a QJsonObject to store the response data
    bool transferResult = db.transferAmount(fromAccountNumber, toAccountNumber, transferAmount);  // Perform the transfer in the database
    QString emailBody;  // String to hold the email body
    response["status"] = "transfer_response";  // Set status in response
    if (transferResult == true)  // Check if the transfer was successful
    {
        response["transsfer_Result"] = "Transfer successful";  // Set success message in response
        emailBody = QString("Dear Client,\nWe want to inform you that you have received %1 L.E from account number: %2\n\nBest Regards,\nIMT_ITIDA Bank")
                        .arg(QString::number(transferAmount))  // Include transfer amount in email body
                        .arg(fromAccountNumber);  // Include sender's account number in email body
        QString to = db.getAccountEmail(toAccountNumber);  // Get recipient's email address from the database
        if (!to.isEmpty())  // Check if recipient email is not empty
        {
            QString subject = "Transfer Notification";  // Subject of the email
            emit sendEmailSignal(to, subject, emailBody);  // Emit the email signal with the recipient, subject, and body
        }
        else
        {
            qDebug() << "Account not found or No email provided";  // Log if account not found or email is not provided
        }
    }
    else
    {
        response["transsfer_Result"] = "Transfer failed";  // Set failure message in response
    }

    emit sendMessageSignal(QJsonDocument(response).toJson());  // Emit the response as a JSON message
}
