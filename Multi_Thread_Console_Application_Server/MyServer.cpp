#include "MyServer.h"

MyServer::MyServer(QObject *parent)
    : QTcpServer{parent},qin{stdin},qout{stdout}
{}

void MyServer::StartServer()
{
    qout<<"Enter Server_Port to Listen to => ";
    qout.flush();
    Port = qin.readLine().toInt();

    this->listen(QHostAddress::Any,Port);
    if(isListening())
    {
        qout<<"Server is up and listening to port =>"<<Port<<Qt::endl;
    }
    else
    {
         qout<<"Server can't listen to port =>"<<Port<<Qt::endl;
    }
}

void MyServer::incomingConnection(qintptr handle)
{
    qDebug()<<"Client =>"<<handle<<" Connecting........"<<Qt::endl;
    MyServerHandler* serverhandler =new MyServerHandler(handle);
    connect(serverhandler,&QThread::finished,serverhandler,&QThread::deleteLater);
    serverhandler->start();
}
