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

void User_Class::GetTransactionHistory(const QString &accountNumber, int count)
{
    QJsonArray transactions = db.getTransactionHistory(accountNumber, count);

    QJsonObject response;
    response["status"] = "transaction_history_response";
    response["account_number"] = accountNumber;
    response["transactions"] = transactions;
    emit sendMessageSignal(QJsonDocument(response).toJson());
}

void User_Class::MakeTransactionRequest(const QString &accountNumber, int transactionAmount, const QString &transactionType)
{
    QJsonObject response;
    QString  emailBody;
    if (transactionType =="Withdrow")
    {
        transactionAmount*=-1;
    }

    bool transactionResult = db.makeTransaction(accountNumber, transactionAmount);
    response["status"] = "transaction_amount_response";
    if (transactionResult==true)
    {
        response["transaction_Result"] = "Transaction successful";
        emailBody = QString("Dear Client,\nWe want to inform you that your transaction request succeeded.\nYou "+transactionType+" "+QString::number(transactionAmount)+" L.E\n\nBest Regards,\nIMT_ITIDA Bank");

    }
    else
    {
        response["transaction_Result"] = "Transaction failed";
        emailBody = QString("Dear Client,\nWe regret to inform you that your transaction request is failed.\nBest Regards,\nIMT_ITIDA Bank");

    }


    QString to = "nmo12416@gmail.com";  // Replace with the actual recipient email
    QString subject = "Transaction Notification";

   emit sendEmailSignal(to, subject, emailBody);

   emit sendMessageSignal(QJsonDocument(response).toJson());
}



void User_Class::TransferAmountRequest(const QString &fromAccountNumber, const QString &toAccountNumber, int transferAmount)
{


    QJsonObject response;
    bool transferResult = db.transferAmount(fromAccountNumber, toAccountNumber, transferAmount);
    QString  emailBody;
    response["status"] = "transfer_response";
    if (transferResult==true)
    {
        response["transsfer_Result"] = "Transfer successful";
        emailBody = QString("Dear Client,\nWe want to inform you that you have received "+QString::number(transferAmount)+" L.E from account number: "+fromAccountNumber+"\n\nBest Regards,\nIMT_ITIDA Bank")
                        .arg(transferAmount)
                        .arg(fromAccountNumber)
                        .arg(toAccountNumber);
        QString to = db.getAccountEmail(toAccountNumber);  // Replace with the actual recipient email
        if (!to.isEmpty()) {
            QString subject = "Transfer Notification";
            emit sendEmailSignal(to, subject, emailBody);
        } else {
            qDebug() << "Account not found or No email provided";
        }


    }
    else
    {
        response["transsfer_Result"] = "Transfer failed";

    }


    emit sendMessageSignal(QJsonDocument(response).toJson());

    // QString to = "nmo12416@gmail.com";  // Replace with the actual recipient email
    // QString subject = "Transfer Notification";

    // emit sendEmailSignal(to, subject, emailBody);



}

