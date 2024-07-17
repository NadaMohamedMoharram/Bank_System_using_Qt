#ifndef MYCLIENT_H
#define MYCLIENT_H
//
#include <QObject>
#include <QTcpSocket>  /// i use it t to create the socket
#include<QString>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include<QMessageBox>
//
#include"qaesencryption.h"

// #include<Qca-qt5>
// #include <QCA-qt5/QCA>
// #include <QtCrypto>

#include<QBuffer>
class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = nullptr);
    void ConnectToDevice(QString ip,qint32 port);
    void Disconnect();
    void WriteData(QString data);
    void sendRequest(const QJsonObject &request);
    void sendEmail(const QString &to, const QString &subject, const QString &body);
  //  QString encryptData(const QString &data);

signals:
    void Connection();
    void Disconnected();
    void ErrorOccurred(QAbstractSocket::SocketError socketError);
    void StateChanged(QAbstractSocket::SocketState socketState);
  //  void ReadyRead(QString data);
    void ReadyRead(const QJsonObject &request);
private slots:
    void onConnection();
    void onDisconnected();
    void onErrorOccurred(QAbstractSocket::SocketError socketError);
    void onStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();
private:
    QString ip;
    qint32 port;
    QTcpSocket socket;
};

#endif // MYCLIENT_H
