#include "mainwindow.h"
#include "ui_mainwindow.h"



enum GUI_Windows
{
  LoginPage=0,
UserPage,
ViewTransactionPage,
MakeTransactionPage,
MakeTransferAmountPage,
AdminPage,
AdminViewTransactionPage,
AdminViewBankDatabasePage,
AdminCreateUserPage,
AdminUpdateUserPage
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

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    QStringList options;
    options << "None" << "Deposit" << "Withdrow";
    ui->comboBox_UserTransactionType->addItems(options);

    Images_init();




}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Images_init()
{
    QPixmap pix("D:\\ITIDA_Scholarship\\Final project\\images.ico"); // Loading an image
    ui->pic1_bankLogo->setPixmap(pix); // Setting the image to a label

    QPixmap pix2("D:\\ITIDA_Scholarship\\Final project\\OIP.png"); // Loading another image
    ui->pic2_userame->setPixmap(pix2); // Setting the image to a label

    QPixmap pix3("D:\\ITIDA_Scholarship\\Final project\\password.png"); // Loading another image
    ui->pic3_password->setPixmap(pix3); // Setting the image to a label

}


/******************************** MainWindow slots *******************************************/

void MainWindow::onConnectionDevice()
{
    qInfo()<<"Client has connected to the server....\n";

}

void MainWindow::onDisconnectedDevice()
{
    qInfo()<<"Client has disconnected from the server....\n";

}

void MainWindow::onErrorOccurredDevice(QAbstractSocket::SocketError socketError)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    qInfo()<<meta.valueToKey(socketError)<<"\n";

}

void MainWindow::onStateChangedDevice(QAbstractSocket::SocketState socketState)
{
    QMetaEnum meta = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    qInfo()<<meta.valueToKey(socketState)<<"\n";

}



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
            handleAccountNumberResponse(response);

        }
        else if(response["status"].toString() == "account_balance_response")
        {
            handleAccountBalancerResponse(response);

        }
        else if(response["status"].toString() == "transaction_history_response")
        {
            displayTransactionHistory(response);

        }
        else if(response["status"].toString() == "transaction_amount_response")
        {
            QString  emailBody;

            if (response["transaction_Result"].toString() == "Transaction successful")
            {
                QMessageBox::information(nullptr, "Transaction Response", "Transaction successful.");
                emailBody = QString("Transaction success.");

            }
                else
            {
                QMessageBox::critical(nullptr, "Transaction Response", "Transaction failed. No suffecient balance");
                emailBody = QString("Transaction failed.");

            }

            QString to = "nmo12416@gmail.com";  // Replace with the actual recipient email
            QString subject = "Transaction Notification";

          // client.sendEmail(to, subject, emailBody);


        }
        else if(response["status"].toString()=="transfer_response")
        {

            if (response["transsfer_Result"].toString() == "Transfer successful")
            {
                QMessageBox::information(nullptr, "Transfer Response", "Transfer successful.");

            }
            else
            {
                QMessageBox::critical(nullptr, "Transfer Response", "Transfer failed.Please check account number or transfer amount and try again.");

            }
        }

        else if(response["status"].toString() == "ViewBankDatabase_response")
        {
            displayDatabaseData(response);
        }

        else if(response["status"].toString() == "CreateUser_response")
        {
            if (response["NewUser_Result"].toString() == "Create new user successful")
                QMessageBox::information(nullptr, "New User Response", "Create new user successful.");
            else
                QMessageBox::critical(nullptr, "New User Response", "Create new user failed.");

        }

        else if(response["status"].toString() == "DeleteUser_response")
        {
            if (response["DeleteUser_Result"].toString() == "Delete user successful")
                QMessageBox::information(nullptr, "Delete user Response", "Delete user successful.");
            else
                QMessageBox::critical(nullptr, "Delete User Response", "Delete user failed. This account number doesn't exist.Try again");

        }
        else if(response["status"].toString() == "UpdateUser_response")
        {
            if (response["UpdateUser_Result"].toString() == "Update user successful")
                QMessageBox::information(nullptr, "Update user Response", "Update user successful.");
            else
                QMessageBox::critical(nullptr, "Update User Response", "Update user failed.Try again");

        }
        else
        {
            qInfo()<<"invalid response"<<Qt::endl;
            QMessageBox::critical(nullptr, "Error", "something wrong happens in your request. try to start again");


        }


}


/******************************** Responses *******************************************/

void MainWindow::handleLoginResponse(const QJsonObject& response)
{
    QString authority = response["authority"].toString();
    this->client_authority =authority;
    this->client_accountNumber=response["account_number"].toString();
    if (authority == "user")
    {
        ui->Login_page->setCurrentIndex(UserPage);
        ui->Label_textUser->setText("Welcome "+this->client_username);
    }
    else if (authority == "admin")
    {
        ui->Login_page->setCurrentIndex(AdminPage);

    }

}




void MainWindow::handleAccountNumberResponse(const QJsonObject& response)
{
     QString accountNumber = response["account_number"].toString();
     if (accountNumber.isEmpty())
        QMessageBox::critical(nullptr, "Error", "This username doesn't exist");
    else
    QMessageBox::information(nullptr, "Information", "This is your account number message=>"+accountNumber);

}

void MainWindow::handleAccountBalancerResponse(const QJsonObject& response)
{
    int balance = response["balance"].toInt();
    QString str_balance= QString::number(balance);

    if(balance<=0)
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

    */


    QJsonArray jsonArray = jsonObject["data"].toArray(); // Assuming 'data' key holds the array

    // Set up the table widget
    ui->TW_AdminViewBankDatabase->clear();
    ui->TW_AdminViewBankDatabase->setRowCount(0);
    ui->TW_AdminViewBankDatabase->setColumnCount(8); // 8 columns for user data

    QStringList headers;
    headers << "Username" << "AccountNumber" << "Autority" << "Balance" << "Email" << "FullName" << "Age" << "Password";
    ui->TW_AdminViewBankDatabase->setHorizontalHeaderLabels(headers);

    // Add rows for each record
    for (const QJsonValue &value : jsonArray) {
        QJsonObject record = value.toObject();
        int currentRow = ui->TW_AdminViewBankDatabase->rowCount();
        ui->TW_AdminViewBankDatabase->insertRow(currentRow);

        ui->TW_AdminViewBankDatabase->setItem(currentRow, 0, new QTableWidgetItem(record["Username"].toString()));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 1, new QTableWidgetItem(record["AccountNumber"].toString()));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 2, new QTableWidgetItem(record["Autority"].toString()));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 3, new QTableWidgetItem(QString::number(record["Balance"].toInt())));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 4, new QTableWidgetItem(record["Email"].toString()));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 5, new QTableWidgetItem(record["FullName"].toString()));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 6, new QTableWidgetItem(QString::number(record["Age"].toInt())));
        ui->TW_AdminViewBankDatabase->setItem(currentRow, 7, new QTableWidgetItem(record["Password"].toString()));

        // QJsonArray transactions = record["Transactions"].toArray();

        // // Iterate through the transactions and add them as rows below the main record
        // for (const QJsonValue &transValue : transactions) {
        //     QJsonObject transaction = transValue.toObject();
        //     currentRow = ui->TW_AdminViewBankDatabase->rowCount();
        //     ui->TW_AdminViewBankDatabase->insertRow(currentRow);

        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 0, new QTableWidgetItem("    Transaction"));
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 1, new QTableWidgetItem());
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 2, new QTableWidgetItem());
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 3, new QTableWidgetItem(QString::number(transaction["Amount"].toInt())));
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 4, new QTableWidgetItem(transaction["date"].toString()));
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 5, new QTableWidgetItem(transaction["type"].toString()));
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 6, new QTableWidgetItem());
        //     ui->TW_AdminViewBankDatabase->setItem(currentRow, 7, new QTableWidgetItem());
        // }
    }

    ui->Login_page->setCurrentIndex(AdminViewBankDatabasePage);

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

        return;
    }

    if (username.contains(' ') || password.contains(' ') )
    {
        QMessageBox::warning(this, "Login", "Invalid username or password.Please enter both username and password without spaces.");

        return;
    }


    QString ip = ui->leIP->text();
   // qint32 port = ui->lePort->text().toInt();
    qint32 port=321;
    client.ConnectToDevice(ip,port);


    QJsonObject loginRequest;
    loginRequest["type"] = "login";
    loginRequest["username"] = username;
    loginRequest["password"] = password;

    // Convert QJsonObject to QJsonDocument
    QJsonDocument jsonDoc(loginRequest);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}



void MainWindow::on_UserGetAccountNo_PB_clicked()
{
    QString username=this->client_username;
    QJsonObject request;
    request["type"] = "GetAccountNumber";
    request["username"] = username;
    qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
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
    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Error", "Invalid account number.Please try again.");

        return;
    }



    QJsonObject request;
    request["type"] = "ViewAccountBalance";
    request["account_number"] = accountNumber;

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
        QMessageBox::warning(this, "View Transaction", "Please enter account number.");

        return;
    }
    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Error", "Invalid account number.Please try again.");

        return;
    }
     if(accountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "View Transaction", "Wrong account number.please try again");
        return;

    }

    QJsonObject request;
    request["type"] = "ViewTransactionHistory";
    request["account_number"] = accountNumber;
    request["count"] = count;

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

        return;
    }
    if(accountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "Make Transaction Request", "Wrong account number.please try again");
        return;

    }
    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Make Transaction Request", "Invalid account number.Please try again.");

        return;
    }

    if ( transactionAmount <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid transfer amount.");
        return;
    }

    if (transactionType=="None") {
        QMessageBox::warning(this, "Make Transaction Request", "Please enter Transaction Type.");

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

    // Validate the inputs
    if (fromAccountNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "From account number cannot be empty.");
        return;
    }

    if(fromAccountNumber!=this->client_accountNumber)
    {
        QMessageBox::critical(this, "Input Error", "Wrong account number.please try again");
        return;

    }

    if (toAccountNumber.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "To account number cannot be empty.");
        return;
    }

    if ( transferAmount <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid transfer amount.");
        return;
    }

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

    if (fromAccountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Make Transfer Request", "Invalid sender account number.Please try again.");

        return;
    }

    if(toAccountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Make Transfer Request","Please enter the receiver account number.");
        return;

    }

    if (toAccountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Make Transfer Request", "Invalid receiver account number.Please try again.");

        return;
    }

    if (transferAmount<=0) {
        QMessageBox::warning(this, "Make Transfer Request", "Please enter a valid transfer amount.");

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
        QMessageBox::critical(this, "Get Account Request", "username is required");
        return;
    }

    if (username.contains(' ') )
    {
        QMessageBox::critical(this, "Get Account Request", "Invalid username.Please try again.");

        return;
    }

    QJsonObject request;
    request["type"] = "Admin_GetAccountNumber";
    request["username"] = username;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);

}




void MainWindow::on_Admin_ViewAcountBalance_PB_clicked()
{
    bool ok;
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"),
                                                  tr("Enter account number:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || accountNumber.isEmpty())
    {
        QMessageBox::critical(this, "View Account Balance Request", "Account number is required");
        return;
    }

    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "View Account Balance Request", "Invalid account number.Please try again.");

        return;
    }




    QJsonObject request;
    request["type"] = "Admin_ViewAccountBalance";
    request["account_number"] = accountNumber;

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

    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "View Transaction Request", "Invalid account number.Please try again.");

        return;
    }


    QJsonObject request;
    request["type"] = "Admin_ViewTransactionHistory";
    request["account_number"] = accountNumber;
    request["count"] = count;

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
    // ui->Login_page->setCurrentIndex(AdminViewBankDatabasePage);

    QJsonObject request;
    request["type"] = "Admin_ViewBankDatabase";


    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);

}

/************************************create user**************************/
void MainWindow::on_Admin_CreateNewUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminCreateUserPage);
}


void MainWindow::on_Back_AdminCreateUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);

}


void MainWindow::on_Confirm_AdminCreateUser_PB_clicked()
{
    QString FullName =ui->LE_CreatUser_FullName->text();
    int Age =ui->LE_CreatUser_Age->text().toInt();
    QString Username =ui->LE_CreatUser_UserName->text();
    QString Password =ui->LE_CreatUser_Password->text();
    QString Email =ui->LE_CreatUser_Email->text();
    QString AccountNo =ui->LE_CreatUser_AccountNumber->text();
    int Balance=0;
    QString Authority="user";

    if (FullName.isEmpty()) {
        QMessageBox::warning(this, "Create user Request", "Please enter Full name.");

        return;
    }

    if (Username.isEmpty()) {
        QMessageBox::warning(this, "Create user Request", "Please enter Username.");

        return;
    }

    if (Username.contains(' ') )
    {
        QMessageBox::critical(this, "Create user Request", "Invalid Username.Please try again.");

        return;
    }

    if (Password.isEmpty()) {
        QMessageBox::warning(this, "Create user Request", "Please enter Password.");

        return;
    }

    if (Password.contains(' ') )
    {
        QMessageBox::critical(this, "Create user Request", "Invalid Password.Please try again.");

        return;
    }

    if (Email.isEmpty()) {
        QMessageBox::warning(this, "Create user Request", "Please enter Email.");

        return;
    }

    if (Email.contains(' ') )
    {
        QMessageBox::critical(this, "Create user Request", "Invalid Email.Please try again.");

        return;
    }

    if (AccountNo.isEmpty()) {
        QMessageBox::warning(this, "Create user Request", "Please enter Account number.");

        return;
    }
    if (AccountNo.contains(' ') )
    {
        QMessageBox::critical(this, "Create user Request", "Invalid Account Number.Please try again.");

        return;
    }






    // Create a JSON object with the user data
    QJsonObject userData;
    userData["FullName"] = FullName;
    userData["Age"] = Age;
    userData["Username"] = Username;
    userData["Password"] = Password;
    userData["Email"] = Email;
    userData["AccountNumber"] = AccountNo;
    userData["Balance"] = Balance;
    userData["Authority"] = Authority;
    userData["Transactions"] = QJsonArray(); // Empty array for transactions

    // Create a request object
    QJsonObject request;
    request["type"] = "Admin_CreateUser";
    request["data"] = userData;

    // Convert QJsonDocument to string
    QJsonDocument jsonDoc(request);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);

    // Send the JSON string to the server
    client.WriteData(jsonString);


}

/***********************   delete user *************************/
void MainWindow::on_Admin_DeleteUser_PB_clicked()
{

    bool ok;
    QString accountNumber = QInputDialog::getText(this, tr("Account Number"),
                                                  tr("Enter account number:"), QLineEdit::Normal,
                                                  "", &ok);
    if (!ok || accountNumber.isEmpty())
    {
        QMessageBox::critical(this, "Delete user Request", "Account number is required");
        return;
    }


    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Delete user Request", "Invalid account number.Please try again.");

        return;
    }


    QJsonObject request;
    request["type"] = "Admin_DeleteUser";
    request["account_number"] = accountNumber;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}




/******************************update user****************************************/
void MainWindow::on_Admin_UpdateUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminUpdateUserPage);
}


void MainWindow::on_Confirm_AdminUpdateUser_PB_clicked()
{
    QString accountNumber = ui->LE_UpdateUser_AccountNumber->text();
    QString fullName = ui->LE_UpdateUser_FullName->text();
    int age = ui->LE_UpdateUser_Age->text().toInt();
    QString username = ui->LE_UpdateUser_UserName->text();
    QString password = ui->LE_UpdateUser_Password->text();
    QString email = ui->LE_UpdateUser_Email->text();


    if (accountNumber.isEmpty()) {
        QMessageBox::warning(this, "Update user Request", "Please enter Account number.");

        return;
    }

    if (accountNumber.contains(' ') )
    {
        QMessageBox::critical(this, "Update user Request", "Invalid account number.Please try again.");

        return;
    }

    if (fullName.isEmpty()) {
        QMessageBox::warning(this, "Update user Request", "Please enter Full name.");

        return;
    }

    if (age<=0)
    {
        QMessageBox::critical(this, "Update user Request", "Invalid age. Please try again.");

        return;
    }

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Update user Request", "Please enter Username.");

        return;
    }

    if (username.contains(' ') )
    {
        QMessageBox::critical(this, "Update user Request", "Invalid Username.Please try again.");

        return;
    }

    if (password.isEmpty()) {
        QMessageBox::warning(this, "Update user Request", "Please enter Password.");

        return;
    }

    if (password.contains(' ') )
    {
        QMessageBox::critical(this, "Update user Request", "Invalid Password.Please try again.");

        return;
    }

    if (email.isEmpty()) {
        QMessageBox::warning(this, "Update user Request", "Please enter Email.");

        return;
    }

    if (email.contains(' ') )
    {
        QMessageBox::critical(this, "Update user Request", "Invalid Email.Please try again.");

        return;
    }



    QJsonObject newData;
    // if (!fullName.isEmpty()) newData["FullName"] = fullName;
    // if (age != 0) newData["Age"] = age;
    // if (!username.isEmpty()) newData["Username"] = username;
    // if (!password.isEmpty()) newData["Password"] = password;
    // if (!email.isEmpty()) newData["Email"] = email;


     newData["FullName"] = fullName;
     newData["Age"] = age;
     newData["Username"] = username;
     newData["Password"] = password;
     newData["Email"] = email;


    QJsonObject request;
    request["type"] = "Admin_UpdateUser";
    request["account_number"] = accountNumber;
    request["data"] = newData;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}




void MainWindow::on_Back_AdminUpdateUser_PB_clicked()
{
    ui->Login_page->setCurrentIndex(AdminPage);
}

