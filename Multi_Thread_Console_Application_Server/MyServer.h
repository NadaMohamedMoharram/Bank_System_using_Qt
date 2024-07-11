#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTextStream>
#include<QDebug>
#include<MyServerHandler.h>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = nullptr);
    void StartServer();
signals:

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
private:
    QTextStream qin;
    QTextStream qout;
    qint32 Port;
};

#endif // MYSERVER_H
