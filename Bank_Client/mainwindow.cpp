#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QMessageBox"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>


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
    ui->Login_page->setCurrentIndex(0);

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
}
/*****************************************************************************************/

void MainWindow::handleLoginResponse(const QJsonObject& response)
{
    QString authority = response["authority"].toString();
    if (authority == "user")
    {
        ui->Login_page->setCurrentIndex(1);
    }
    else if (authority == "admin")
    {
        ui->Login_page->setCurrentIndex(2);

    }
}




void MainWindow::handleAccountNumberResponse(const QJsonObject& response)
{
     QString accountNumber = response["account_number"].toString();
    QMessageBox::information(nullptr, "Information", "This is your account number message=>"+accountNumber);

}

/**************************************************************************/


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
    Qstring username=this->client_username;
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
    QJsonObject request;
    request["type"] = "GetAccountNumber";
    request["username"] = username;
    qInfo()<<"username=>"<<username<<Qt::endl;

    QJsonDocument jsonDoc(request);

    // Convert QJsonDocument to string
    QString jsonString = jsonDoc.toJson(QJsonDocument::Compact);
    client.WriteData(jsonString);
}

