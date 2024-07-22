#ifndef MYSERVER_H  // Include guard to prevent multiple inclusions of this header file
#define MYSERVER_H

#include <QObject>  // Include QObject class for base functionality
#include <QTcpServer>  // Include QTcpServer class to handle TCP server functionality
#include <QTextStream>  // Include QTextStream class for reading/writing text streams
#include <QDebug>  // Include QDebug class for debugging output
#include <MyServerHandler.h>  // Include custom header for MyServerHandler class

class MyServer : public QTcpServer  // Define MyServer class inheriting from QTcpServer
{
    Q_OBJECT  // Macro required for using signals and slots
public:
    explicit MyServer(QObject *parent = nullptr);  // Constructor declaration, with an optional parent QObject
    void StartServer();  // Public method to start the server
signals:
         // Signals for communication (none defined here)
protected:
    void incomingConnection(qintptr handle) override;  // Override method to handle incoming TCP connections
private:
    QTextStream qin;  // QTextStream object for input operations (e.g., reading data from sockets)
    QTextStream qout;  // QTextStream object for output operations (e.g., writing data to sockets)
    qint32 Port;  // Integer to store the port number on which the server listens
};

#endif // MYSERVER_H  // End of the include guard
