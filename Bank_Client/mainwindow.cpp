#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMessageBox"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

#include<QInputDialog>
enum GUI_Windows
{
  LoginPage=0,
UserPage,
ViewTransactionPage,
MakeTransactionPage,
MakeTransferAmountPage,
AdminPage,
AdminViewTransactionPage,
AdminViewBankDatabasePage
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&client,&MyClient::Connection,this,&MainWindow::onConnectionDevice);
    connect(&client,&MyClient::Disconnected,this,&MainWindow::onDisconnectedDevice);
    connect(&client,&MyClient::ErrorOccurred,this,&MainWindow::onErrorOccurredDevice);
    connect(&client,&MyClient::StateChanged,this,&MainWindow::onStateChangedDevice);
    connect(&client,&MyClient::ReadyRead,this,&MainWindow::onReadyReadDevice);
    ui->Login_page->setCurrentIndex(LoginPage);

    QStringList options;
    options << "None" << "Deposit" << "Withdrow";
    ui->comboBox_UserTransactionType->addItems(options);

}
MainWindow::~MainWindow()
{
    delete ui;
}



/***************************************************************************/

void MainWindow::onConnectionDevice()
{
   // ui->lwData->addItem("Client has connected to the server....");
    qInfo()<<"Client has connected to the server....\n";

}

void MainWindow::onDisconnectedDevice()
{
   // ui->lwData->addItem("Client has disconnected from the server....");
    qInfo()<<"Client has disconnected from the server....\n";

}

void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
  //  ui->lwData->addItem(meta.valueToKey(socketError));
    qInfo()<<meta.valueToKey(socketError)<<"\n";

}

void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    //ui->lwData->addItem(meta.valueToKey(socketState));
    qInfo()<<meta.valueToKey(socketState)<<"\n";

}

// void MainWindow::onReadyReadDevice(QString data)
// {
//     QString str = QString("Data Recieved => %1").arg(data);
//     qInfo()<<str<<"\n";
// }


void MainWindow::onReadyReadDevice(const QJsonObject &response)
{
        if (response["status"].toString() == "success")
        {
          handleLoginResponse(response);
        }
        else if (response["status"].toString() == "failed")
        {
            QMessageBox::critical(nullptr, "Error", "Login failed: Invalid username or password.");

        }
        else if(response["status"].toString() == "success_GetAccountNumber")
        {
             qInfo()<<"received response yo get account";
            handleAccountNumberResponse(response);

        }
        else if(response["status"].toString() == "account_balance_response")
        {
            qInfo()<<"received response account_balance";
            handleAccountBalancerResponse(response);

        }
        else if(response["status"].toString() == "transaction_history_response")
        {
            qInfo()<<"received response transaction_history";
            displayTransactionHistory(response);

        }
        else if(response["status"].toString() == "transaction_amount_response")
        {
            qInfo()<<"received response transaction_amount";
            if (response["transaction_Result"].toString() == "Transaction successful")
                QMessageBox::information(nullptr, "Transaction Response", "Transaction successful.");
            else
                QMessageBox::critical(nullptr, "Transaction Response", "Transaction failed. No suffecient balance");

        }

        else if(response["status"].toString() == "ViewBankDatabase_response")
        {
            displayDatabaseData(response);
        }
        else
        {
            qInfo()<<"invalid response"<<Qt::endl;
        }


}
/*****************************************************************************************/

void MainWindow::handleLoginResponse(const QJsonObject& response)
{
    QString authority = response["authority"].toString();
    this->client_authority =authority;
    this->client_accountNumber=response["account_number"].toString();
    if (authority == "user")
    {
        ui->Login_page->setCurrentIndex(UserPage);
    }
    else if (authority == "admin")
    {
        ui->Login_page->setCurrentIndex(AdminPage);

    }
}




void MainWindow::handleAccountNumberResponse(const QJsonObject& response)
{
     QString accountNumber = response["account_number"].toString();
   // this->client_accountNumber=accountNumber;
     if (accountNumber.isEmpty())
        QMessageBox::critical(nullptr, "Error", "This user name doesn't exist");
    else
    QMessageBox::information(nullptr, "Information", "This is your account number message=>"+accountNumber);

}

void MainWindow::handleAccountBalancerResponse(const QJsonObject& response)
{
    int balance = response["balance"].toInt();
    QString str_balance= QString::number(balance);

    if(str_balance.isEmpty())
    QMessageBox::critical(nullptr, "Error", "This account number doesn't exist");
    else
    QMessageBox::information(nullptr, "Account Balance", "The account balance is ==>"+str_balance);

}

void MainWindow::displayTransactionHistory(const QJsonObject& response)
{
    QJsonArray transactions = response["transactions"].toArray();

    if (this->client_authority=="user")
    {
    ui->transactionHistoryTable->setRowCount(transactions.size());
    ui->transactionHistoryTable->setColumnCount(3);
    ui->transactionHistoryTable->setHorizontalHeaderLabels(QStringList() << "Date" << "Amount"<< "type");



    for (int i = 0; i < transactions.size(); ++i) {
        QJsonObject transaction = transactions[i].toObject();
        ui->transactionHistoryTable->setItem(i, 0, new QTableWidgetItem(transaction["date"].toString()));
        ui->transactionHistoryTable->setItem(i, 1, new QTableWidgetItem(QString::number(transaction["Amount"].toInt())));
        ui->transactionHistoryTable->setItem(i, 2, new QTableWidgetItem(transaction["type"].toString()));
    }
    }
    else
    {
  //  QJsonArray transactions = response["transactions"].toArray();
    ui->Admin_transactionHistoryTable->setRowCount(transactions.size());
    ui->Admin_transactionHistoryTable->setColumnCount(3);
    ui->Admin_transactionHistoryTable->setHorizontalHeaderLabels(QStringList() << "Date" << "Amount"<< "type");



    for (int i = 0; i < transactions.size(); ++i) {
        QJsonObject transaction = transactions[i].toObject();
        ui->Admin_transactionHistoryTable->setItem(i, 0, new QTableWidgetItem(transaction["date"].toString()));
        ui->Admin_transactionHistoryTable->setItem(i, 1, new QTableWidgetItem(QString::number(transaction["Amount"].toInt())));
        ui->Admin_transactionHistoryTable->setItem(i, 2, new QTableWidgetItem(transaction["type"].toString()));
    }
    }

}

void MainWindow::displayDatabaseData(const QJsonObject &jsonObject)
{

    /*
QJsonArray jsonArray = jsonObject["data"].toArray(); // Assuming 'data' key holds the array

    // Clear existing items in the list widget
    ui->LW_AdminViewBankDatabase->clear();

    // Start with the opening bracket of the JSON array
    ui->LW_AdminViewBankDatabase->addItem("[");

    // Iterate through the JSON array and add each item to the list widget
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonObject record = jsonArray[i].toObject();

        // Convert the record to a string in JSON format
        QString recordString = QString("{ \"Username\": \"%1\", \"AccountNumber\": \"%2\", \"Autority\": \"%3\", \"Balance\": %4, \"Email\": \"%5\", \"FullName\": \"%6\", \"Age\": %7, \"Password\": \"%8\", \"Transactions\": [")
                               .arg(record["Username"].toString())
                               .arg(record["AccountNumber"].toString())
                               .arg(record["Autority"].toString())
                               .arg(record["Balance"].toInt())
                               .arg(record["Email"].toString())
                               .arg(record["FullName"].toString())
                               .arg(record["Age"].toInt())
                               .arg(record["Password"].toString());

        // Add the opening bracket of the record object
        ui->LW_AdminViewBankDatabase->addItem("    " + recordString);

        QJsonArray transactions = record["Transactions"].toArray();

        // Iterate through the transactions and add them as sub-items
        for (int j = 0; j < transactions.size(); ++j) {
            QJsonObject transaction = transactions[j].toObject();
            QString transactionString = QString("        { \"Amount\": %1, \"date\": \"%2\", \"type\": \"%3\" }")
                                          .arg(transaction["Amount"].toInt())
                                          .arg(transaction["date"].toString())
                                          .arg(transaction["type"].toString());

            // Add the transaction info as a sub-item
            ui->LW_AdminViewBankDatabase->addItem(transactionString + (j < transactions.size() - 1 ? "," : ""));
        }

        // Add the closing bracket of the transactions array and the record object
        ui->LW_AdminViewBankDatabase->addItem("    ]" + QString(i < jsonArray.size() - 1 ? "}," : "}"));
    }

    // Add the closing bracket of the JSON array
    ui->LW_AdminViewBankDatabase->addItem("]");

*/






    QJsonArray jsonArray = jsonObject["data"].toArray(); // Assuming 'data' key holds the array

    // Clear existing items in the list widget
    ui->LW_AdminViewBankDatabase->clear();

    // Start with the opening bracket of the JSON array
    ui->LW_AdminViewBankDatabase->addItem("[");

    // Iterate through the JSON array and add each item to the list widget
    for (int i = 0; i < jsonArray.size(); ++i) {
        QJsonObject record = jsonArray[i].toObject();

        // Convert the record to a string in JSON format
        QString recordString = QString("{\n"
                                       "    \"Username\": \"%1\",\n"
                                       "    \"AccountNumber\": \"%2\",\n"
                                       "    \"Autority\": \"%3\",\n"
                                       "    \"Balance\": %4,\n"
                                       "    \"Email\": \"%5\",\n"
                                       "    \"FullName\": \"%6\",\n"
                                       "    \"Age\": %7,\n"
                                       "    \"Password\": \"%8\",\n"
                                       "    \"Transactions\": [")
                                   .arg(record["Username"].toString())
                                   .arg(record["AccountNumber"].toString())
                                   .arg(record["Autority"].toString())
                                   .arg(record["Balance"].toInt())
                                   .arg(record["Email"].toString())
                                   .arg(record["FullName"].toString())
                                   .arg(record["Age"].toInt())
                                   .arg(record["Password"].toString());

        // Add the opening bracket of the record object
        ui->LW_AdminViewBankDatabase->addItem(recordString);

        QJsonArray transactions = record["Transactions"].toArray();

        // Iterate through the transactions and add them as sub-items
        for (int j = 0; j < transactions.size(); ++j) {
            QJsonObject transaction = transactions[j].toObject();
            QString transactionString = QString("        {\n"
                                                "            \"Amount\": %1,\n"
                                                "            \"date\": \"%2\",\n"
                                                "            \"type\": \"%3\"\n"
                                                "        }")
                                            .arg(transaction["Amount"].toInt())
                                            .arg(transaction["date"].toString())
                                            .arg(transaction["type"].toString());

            // Add the transaction info as a sub-item
            ui->LW_AdminViewBankDatabase->addItem(transactionString + (j < transactions.size() - 1 ? "," : ""));
        }

        // Add the closing bracket of the transactions array and the record object
        ui->LW_AdminViewBankDatabase->addItem("    ]" + QString(i < jsonArray.size() - 1 ? ",\n}" : "\n}"));
    }

    // Add the closing bracket of the JSON array
    ui->LW_AdminViewBankDatabase->addItem("]");
}



/*************************************************************************/


void MainWindow::on_PB_Login_clicked()
{
    qInfo()<<"in the func";

    QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_password->text();
    this->client_username=username;
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please enter both username and password.");
        qInfo()<<"LoginPlease enter both username and password";

        return;
    }

    // QString ip="192.168.56.1";
    // QString port_str="1234";
    // qint32 port= port_str.toInt();
    QString ip = ui->leIP->text();
    qint32 port = ui->lePort->text().toInt();

    client.ConnectToDevice(ip,port);


    //  qInfo()<<"/**************************/\n";
    QJsonObject loginRequest;
    loginRequest["type"] = "login";
    loginRequest["username"] = username;
    loginRequest["password"] = password;

    //client.sendRequest(loginRequest); // Send the login request
    // Convert QJsonObject to QJsonDocument
    QJsonDocument jsonDoc(loginRequest);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}



// QString ConvertToString()



void MainWindow::on_UserGetAccountNo_PB_clicked()
{
    qInfo()<<"in get account"<<Qt::endl;
   // QString username= ui->lineEdit_username->text();
    QString username=this->client_username;
    QJsonObject request;
    request["type"] = "GetAccountNumber";
    request["username"] = username;
    qInfo()<<"username=>"<<username<<Qt::endl;

   // sendMessage(QJsonDocument(request).toJson());
    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
     qInfo()<<" get account request sent to server"<<Qt::endl;
}


void MainWindow::on_UserAccountBalance_PB_clicked()
{
    bool ok;
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"),
                                                  tr("Enter your account number:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || accountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Account number is required");
        return;
    }



    QJsonObject request;
    request["type"] = "ViewAccountBalance";
    request["account_number"] = accountNumber;
   // qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}


void MainWindow::on_UserViewTransaction_PB_2_clicked()
{


    ui->Login_page->setCurrentIndex(ViewTransactionPage);

}

void MainWindow::on_UserShowTransactin_PB_clicked()
{
    QString accountNumber=ui->lineEdit_UserAccountNumber->text();

    int count=ui->spinBox_UserCount->value();

    if (accountNumber.isEmpty()) {
        QMessageBox::warning(this, "View Transaction", "Please enter both account number.");
      //  qInfo()<<"LoginPlease enter both username and password";

        return;
    }
    else if(accountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "View Transaction", "Wrong account number.please try again");
        return;

    }

    QJsonObject request;
    request["type"] = "ViewTransactionHistory";
    request["account_number"] = accountNumber;
    request["count"] = count;
    // qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}

void MainWindow::on_UserLogout_PB_clicked()
{
    ui->Login_page->setCurrentIndex(LoginPage);
}


void MainWindow::on_Back_PB_clicked()
{
     ui->Login_page->setCurrentIndex(UserPage);
}





void MainWindow::on_UserMakeTransaction_PB_clicked()
{
    ui->Login_page->setCurrentIndex(MakeTransactionPage);
   //  ui->listWidget_try->show();
   // ui->listWidget_try->hide();


}

void MainWindow::on_UserTransferAmount_PB_clicked()
{
    ui->Login_page->setCurrentIndex(MakeTransferAmountPage);

}


void MainWindow::on_UserConfirmTransaction_PB_clicked()
{
    QString accountNumber = ui->lineEdit_UserAccountNumber_Transaction->text();
    int transactionAmount = ui->lineEdit_UserTransactionAmount->text().toInt();
    QString transactionType=ui->comboBox_UserTransactionType->currentText();

    if (accountNumber.isEmpty()) {
        QMessageBox::warning(this, "Make Transaction Request", "Please enter account number.");
        //  qInfo()<<"LoginPlease enter both username and password";

        return;
    }
    if(accountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "Make Transaction Request", "Wrong account number.please try again");
        return;

    }
    if (transactionType=="None") {
        QMessageBox::warning(this, "Make Transaction Request", "Please enter Transaction Type.");
        //  qInfo()<<"LoginPlease enter both username and password";

        return;
    }
    QJsonObject request;
    request["type"] = "MakeTransaction";
    request["account_number"] = accountNumber;
    request["transaction_Amount"] = transactionAmount;
    request["transaction_Type"]=transactionType;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}




void MainWindow::on_UserBack_Transaction_PB_clicked()
{
    ui->Login_page->setCurrentIndex(UserPage);
}




/*****  delete it*****/
void MainWindow::on_UserTransfer_PB_clicked()
{
    QString fromAccountNumber = ui->fromAccountNumberLineEdit->text();
    QString toAccountNumber = ui->toAccountNumberLineEdit->text();
    int transferAmount = ui->transferAmountLineEdit->text().toInt();  // Assuming a QSpinBox for transfer amount

    QJsonObject request;
    request["type"] = "TransferAmount";
    request["fromAccountNumber"] = fromAccountNumber;
    request["toAccountNumber"] = toAccountNumber;
    request["transferAmount"] = transferAmount;

    QJsonDocument jsonDoc(request);
    qInfo()<<"in transfer func"<<Qt::endl;
    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}
/**********/

void MainWindow::on_UserTransfer_Back_PB_clicked()
{
    ui->Login_page->setCurrentIndex(UserPage);

}


void MainWindow::on_UserTransfer_confirm_PB_clicked()
{
    QString fromAccountNumber = ui->fromAccountNumberLineEdit->text();
    QString toAccountNumber = ui->toAccountNumberLineEdit->text();
    int transferAmount = ui->transferAmountLineEdit->text().toInt();  // Assuming a QSpinBox for transfer amount

    // QJsonObject request;
    // request["type"] = "TransferAmount";
    // request["fromAccountNumber"] = fromAccountNumber;
    // request["toAccountNumber"] = toAccountNumber;
    // request["transferAmount"] = transferAmount;

    // QJsonDocument jsonDoc(request);
    // qInfo()<<"in transfer func"<<Qt::endl;
    // // Convert QJsonDocument to string
    // QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    // client.WriteData(jsonString);





    /**********************************/

    if (fromAccountNumber.isEmpty()) {
        QMessageBox::critical(this, "Make Transfer Request", "Please enter the sender account number.");
        //  qInfo()<<"LoginPlease enter both username and password";

        return;
    }
    if(fromAccountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "Make Transfer Request", "Wrong sender account number.please try again");
        return;

    }
    if(toAccountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Make Transfer Request","Please enter the receiver account number.");
        return;

    }
    if (transferAmount<=0) {
        QMessageBox::warning(this, "Make Transfer Request", "Please enter a valid transfer amount.");
        //  qInfo()<<"LoginPlease enter both username and password";

        return;
    }
    QJsonObject request;
    request["type"] = "TransferAmount";
    request["fromAccountNumber"] = fromAccountNumber;
    request["toAccountNumber"] = toAccountNumber;
    request["transferAmount"]=transferAmount;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}

/***************************************   Admin page *************************/
void MainWindow::on_Admin_Logout_PB_clicked()
{
    ui->Login_page->setCurrentIndex(LoginPage);
}


void MainWindow::on_Admin_GetAccountNo_PB_clicked()
{

    bool ok;
    QString username = QInputDialog::getText(this, tr("Get Account Number"),
                                                  tr("Enter username:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || username.isEmpty())
    {
        QMessageBox::critical(this, "Error", "username is required");
        return;
    }

    QJsonObject request;
    request["type"] = "Admin_GetAccountNumber";
    request["username"] = username;
    //qInfo()<<"username=>"<<username<<Qt::endl;

    // sendMessage(QJsonDocument(request).toJson());
    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
   // qInfo()<<" get account request sent to server"<<Qt::endl;

}


void MainWindow::on_Admin_ViewAcountBalance_PB_clicked()
{
    bool ok;
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"),
                                                  tr("Enter account number:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || accountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Account number is required");
        return;
    }



    QJsonObject request;
    request["type"] = "Admin_ViewAccountBalance";
    request["account_number"] = accountNumber;
    // qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}


void MainWindow::on_Admin_ViewTransactionHistory_PB_clicked()
{
     ui->Login_page->setCurrentIndex(AdminViewTransactionPage);


}


void MainWindow::on_Back_AdminViewHistory_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);

}


void MainWindow::on_Display_AdminViewHistory_PB_clicked()
{
    QString accountNumber=ui->LineEdit_Admin_AccountNo_ViewHistory->text();

    int count=ui->spinBox__Admin_Count_ViewHistory->value();

    if (accountNumber.isEmpty()) {
        QMessageBox::warning(this, "View Transaction", "Please enter account number.");
        //  qInfo()<<"LoginPlease enter both username and password";

        return;
    }


    QJsonObject request;
    request["type"] = "Admin_ViewTransactionHistory";
    request["account_number"] = accountNumber;
    request["count"] = count;
    // qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}

/**************************************************************************/
void MainWindow::on_Back_AdminViewBankDatabase_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);
}


void MainWindow::on_Admin_ViewBankDatabase_PB_clicked()
{
     ui->Login_page->setCurrentIndex(AdminViewBankDatabasePage);

    QJsonObject request;
    request["type"] = "Admin_ViewBankDatabase";

    // qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);

}

