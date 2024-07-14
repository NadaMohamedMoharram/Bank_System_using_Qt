#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyClient.h"
#include <QMetaEnum>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handleLoginResponse(const QJsonObject& response);
    void handleAccountNumberResponse(const QJsonObject& response);
    void handleAccountBalancerResponse(const QJsonObject& response);
    void displayTransactionHistory(const QJsonObject& response);
public slots:
    void onConnectionDevice();
    void onDisconnectedDevice();
    void onErrorOccurredDevice(QAbstractSocket::SocketError socketError);
    void onStateChangedDevice(QAbstractSocket::SocketState socketState);
  //  void onReadyReadDevice(QString data);
    void onReadyReadDevice (const QJsonObject &request);
private slots:
    void on_PB_Login_clicked();


    void on_UserGetAccountNo_PB_clicked();

    void on_UserAccountBalance_PB_clicked();

    void on_UserViewTransaction_PB_2_clicked();

    void on_UserLogout_PB_clicked();

    void on_Back_PB_clicked();

    void on_UserShowTransactin_PB_clicked();

    void on_UserMakeTransaction_PB_clicked();

    void on_UserBack_Transaction_PB_clicked();

    void on_UserConfirmTransaction_PB_clicked();

    void on_UserTransferAmount_PB_clicked();

    void on_UserTransfer_PB_clicked();

    void on_UserTransfer_Back_PB_clicked();

    void on_UserTransfer_confirm_PB_clicked();

private:
    Ui::MainWindow *ui;
    MyClient client;
    QString client_username;
    QString client_accountNumber;
};
#endif // MAINWINDOW_H
