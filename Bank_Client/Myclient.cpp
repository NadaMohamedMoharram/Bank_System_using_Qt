#include "MyClient.h"

MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    connect(&socket,&QTcpSocket::connected,this,&MyClient::onConnection);
    connect(&socket,&QTcpSocket::disconnected,this,&MyClient::onDisconnected);
    connect(&socket,&QTcpSocket::errorOccurred,this,&MyClient::onErrorOccurred);
    connect(&socket,&QTcpSocket::stateChanged,this,&MyClient::onStateChanged);
    connect(&socket,&QTcpSocket::readyRead,this,&MyClient::onReadyRead);

}

void MyClient::ConnectToDevice(QString ip, qint32 port)
{
    if(socket.isOpen())
    {
        if((this->ip == ip)&&(this->port == port))
        {
            return;
        }
        else
        {
            socket.close();
            this->port = port;
            this->ip = ip;
            socket.connectToHost(this->ip,this->port);
            qInfo()<<"connecting to server.......";


        }
    }
    else
    {
        this->port = port;
        this->ip = ip;
        socket.connectToHost(this->ip,this->port);
        qInfo()<<"connecting to server.......";
    }
}

void MyClient::Disconnect()
{
    if(socket.isOpen())
    {
        socket.close();
    }
}

void MyClient::WriteData(QString data)
{
    if(socket.isOpen())
    {
        socket.write(data.toUtf8());
    }
}

void MyClient::onConnection()
{
    emit Connection();
}

void MyClient::onDisconnected()
{
    emit Disconnected();
}

void MyClient::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    emit ErrorOccurred(socketError);
}

void MyClient::onStateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    emit StateChanged(socketState);
}

// void MyClient::onReadyRead()
// {
//     QByteArray byteArray = socket.readAll();
//     QString data = QString(byteArray);
//     qInfo()<<"received data from server=>"<<data<<Qt::endl;
//     emit ReadyRead(data);
// }


void MyClient::onReadyRead()
{
    QByteArray data = socket.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    // if (!jsonDoc.isNull() && jsonDoc.isObject())
    // {
        QJsonObject response = jsonDoc.object();
    //     if (response["status"].toString() == "success")
    //     {
    //         QMessageBox::information(nullptr, "success", "Login successful.");
    //        // handleLoginResponse(response);
    //     }
    //     else
    //     {
    //         QMessageBox::critical(nullptr, "Error", "Login failed: Invalid username or password.");

    //     }
    // }

    emit ReadyRead(response);
}


/*******************************************************/
void MyClient::sendRequest(const QJsonObject &request)
{
    QJsonDocument doc(request);
    QByteArray data = doc.toJson();

    // Encrypt the data here if necessary
    if(socket.isOpen())
    {
        qInfo()<<"opened\n";
        socket.write(data);
        socket.flush();
    }
   qInfo()<<"closed\n";
}
