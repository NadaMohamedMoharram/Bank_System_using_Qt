#include "MyServerHandler.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

MyServerHandler::MyServerHandler(qint32 ID,QObject *parent)
    : QThread{parent}
{
    this->ID = ID;
}

void MyServerHandler::run()
{
  //  qDebug()<<"Client with ID: "<<ID<<" is running on thread "<<QThread::currentThreadId()<<Qt::endl;
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
    connect(Socket,&QTcpSocket::readyRead,this,&MyServerHandler::onReadyRead,Qt::DirectConnection);
    connect(Socket,&QTcpSocket::disconnected,this,&MyServerHandler::onDisconnected,Qt::DirectConnection);

    sendMessage("Hello From My Server Dear client");
    exec();

}

void MyServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll();
    qDebug()<<"My Server Received Data From Client"<<Qt::endl;
    Operation(QString(ByteArr));

}

void MyServerHandler::Operation(QString Operation)
{
    qDebug()<<Operation<<Qt::endl;
     QJsonDocument jsonDoc = QJsonDocument::fromJson(Operation.toUtf8());
    QJsonObject obj= MyServerHandler::ConvertToJsonObj(Operation);
    // if (!jsonDoc.isNull() && jsonDoc.isObject()) {
    //      obj=jsonDoc.object();

    // } else {
    //     qWarning() << "Failed to parse JSON or the JSON is not an object.";
    //    // return QJsonObject();
    // }

    QString type = obj["type"].toString();

    if (type == "login") {
        QString username = obj["username"].toString();
        QString password = obj["password"].toString();

        MyServerHandler::OnLogin(username,password);

    }

    if(type == "GetAccountNumber")
    {
        QString username = obj["username"].toString();
        MyServerHandler::GetAccountNumber(username);
    }

    if(type == "ViewAccountBalance")
    {
        QString accountNumber = obj["account_number"].toString();
        GetBalance(accountNumber);
    }

    if(type == "ViewTransactionHistory")
    {

    }

    if(type == "MakeTransaction")
    {

    }

    if(type == "TransferAmount ")
    {

    }

    if(type == "ViewBankDatabase")
    {

    }


    if(type == "CreateNewUser")
    {

    }

    if(type == "DeleteUser")
    {

    }

    if(type == "UpdateUser")
    {

    }



    // if(Operation == "Hello")
    // {
    //     sendMessage("Hello Dear Client");
    // }
    // else if(Operation == "What is your name")
    // {
    //     sendMessage("My name is Kerollos Server");
    // }
    // else if(Operation == "What is your Age")
    // {
    //     sendMessage("My Age is 27");
    // }
    // else
    // {
    //     QString str = "This is invalid request\n"
    //     "Hello\n"
    //     "What is your name\n"
    //     "What is your Age\n";
    //     sendMessage(str);
    // }
}

void MyServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {
        Socket->close();
        qDebug()<<"Client => "<<ID<<"has disconnected"<<Qt::endl;
    }
}

void MyServerHandler::sendMessage(QString Message)
{
    if(Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        qDebug()<<"My server Send Data to Client => "<<Qt::endl;
    }
    else
    {
        qDebug()<<"Myserver Can't Send Data to Client => "<<Qt::endl;
    }
}


QJsonObject MyServerHandler::ConvertToJsonObj(QString Message)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(Message.toUtf8());

    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        return jsonDoc.object();

    } else {
        qWarning() << "Failed to parse JSON or the JSON is not an object.";
         return QJsonObject();
    }

}
/***************************/

void MyServerHandler::OnLogin(QString username, QString password)
{
    QString authority= Data_Base.verifyCredentials(username, password);
    QJsonObject response;
    if (!authority.isEmpty())
    {
       // sendMessage("Login successful!");

        qDebug() << "Login successful for user:" << username << "with authority:" << authority << Qt::endl;

        response["status"] = "success";
        response["authority"] = authority;
        sendMessage(QJsonDocument(response).toJson());
        qDebug() << "Login successful for user:" << username << "with authority:" << authority << Qt::endl;
    }
    else
    {
        response["status"] = "failed";
        sendMessage(QJsonDocument(response).toJson());
        qDebug() << "Login failed for user:" << username << Qt::endl;
    }

    // if ( Data_Base.verifyCredentials(username, password) )
    // {
    //     sendMessage("Login successful!");
    //     qDebug() << "Login successful for user:" << username << Qt::endl;



    // }
    // else
    // {
    //     sendMessage("Login failed: Invalid username or password.");
    //     qDebug() << "Login failed for user:" << username << Qt::endl;
    // }
}

void MyServerHandler::GetAccountNumber(QString username)
{
    QJsonObject response;
   // if (loggedInUsers.contains(username) && loggedInUsers[username] == "user")
 //   {
        DataBase db;
        QString accountNumber = db.getAccountNumber(username);
        response["status"] = "success_GetAccountNumber";
        response["account_number"] = accountNumber;
  //  }
    // else
    // {
    //     response["status"] = "failed";
    //     response["account_number"] = "";
    // }
    sendMessage(QJsonDocument(response).toJson());
}

void MyServerHandler::GetBalance(const QString &accountNumber)
{
    DataBase db;
    QString balance = db.getAccountBalance(accountNumber);

    QJsonObject response;
    response["status"] = "account_balance_response";
    response["account_number"] = accountNumber;
    response["balance"] = balance;
    sendMessage(QJsonDocument(response).toJson());
}


