#include "MyServer.h"  // Include the header file for MyServer class

MyServer::MyServer(QObject *parent)  // Constructor definition for MyServer
    : QTcpServer{parent}, qin{stdin}, qout{stdout}  // Initialize base class QTcpServer with parent and QTextStream objects qin and qout
{}

void MyServer::StartServer()
{
    Port = 321;  // Set a fixed port number (321)

    this->listen(QHostAddress::Any, Port);  // Start listening on all available network interfaces at the specified port
    if (isListening())  // Check if the server is successfully listening
    {
        qout << "Server is up and listening to port => " << Port << Qt::endl;  // Output success message with port number
    }
    else
    {
        qout << "Server can't listen to port => " << Port << Qt::endl;  // Output error message if server can't listen
    }
}

void MyServer::incomingConnection(qintptr handle)
{
    qDebug() << "Client =>" << handle << " Connecting........" << Qt::endl;  // Debug message indicating a new client connection with handle
    MyServerHandler* serverhandler = new MyServerHandler(handle);  // Create a new MyServerHandler object for the new client connection
    connect(serverhandler, &QThread::finished, serverhandler, &QThread::deleteLater);  // Connect the finished signal of the handler to its own deletion
    serverhandler->start();  // Start the server handler thread to manage the client connection
}
