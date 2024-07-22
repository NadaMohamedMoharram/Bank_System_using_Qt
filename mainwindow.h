#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>  // Include the base QMainWindow class for the application main window
#include "MyClient.h"  // Include the MyClient class for managing client-side network operations
#include <QMetaEnum>  // Include QMetaEnum for handling enumerations in Qt
#include "qaesencryption.h"  // Include QAESEncryption for AES encryption functionalities

#include "QMessageBox"  // Include QMessageBox for displaying messages to the user
#include <QJsonArray>  // Include QJsonArray for handling JSON arrays
#include <QJsonObject>  // Include QJsonObject for handling JSON objects
#include <QJsonDocument>  // Include QJsonDocument for handling JSON documents
#include <QFile>  // Include QFile for file handling
#include <QPixmap>  // Include QPixmap for handling images
#include <QWidget>  // Include QWidget for basic widget functionalities
#include <QInputDialog>  // Include QInputDialog for input dialogs
#include <QNetworkInterface> // Include the QNetworkInterface header to access network interface information
#include <QHostAddress>      // Include the QHostAddress header to handle IP addresses


#define SERVER_PORT 321  // Define a constant for the server port number

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;  // Forward declaration of the Ui::MainWindow class
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // Macro to enable Qt's meta-object system

public:
    MainWindow(QWidget *parent = nullptr);  // Constructor with an optional parent widget
    ~MainWindow();  // Destructor
    void Images_init();  // Method for initializing images
    void handleLoginResponse(const QJsonObject& response);  // Method to handle login responses
    void handleAccountNumberResponse(const QJsonObject& response);  // Method to handle account number responses
    void handleAccountBalancerResponse(const QJsonObject& response);  // Method to handle account balance responses
    void displayTransactionHistory(const QJsonObject& response);  // Method to display transaction history
    void displayDatabaseData(const QJsonObject &jsonObject);  // Method to display database data

    QString  getLocalIpAddress();
public slots:
    void onConnectionDevice();  // Slot for handling connection events
    void onDisconnectedDevice();  // Slot for handling disconnection events
    void onErrorOccurredDevice(QAbstractSocket::SocketError socketError);  // Slot for handling socket errors
    void onStateChangedDevice(QAbstractSocket::SocketState socketState);  // Slot for handling state changes
    //void onReadyReadDevice(QString data);  // Slot for handling data read events (commented out)
    void onReadyReadDevice(const QJsonObject &request);  // Slot for handling JSON data read events

private slots:
    void on_PB_Login_clicked();  // Slot for handling login button click

    void on_UserGetAccountNo_PB_clicked();  // Slot for handling get account number button click

    void on_UserAccountBalance_PB_clicked();  // Slot for handling account balance button click

    void on_UserViewTransaction_PB_2_clicked();  // Slot for handling view transaction history button click

    void on_UserLogout_PB_clicked();  // Slot for handling user logout button click

    void on_Back_PB_clicked();  // Slot for handling back button click

    void on_UserShowTransactin_PB_clicked();  // Slot for handling show transaction button click

    void on_UserMakeTransaction_PB_clicked();  // Slot for handling make transaction button click

    void on_UserBack_Transaction_PB_clicked();  // Slot for handling back from transaction button click

    void on_UserConfirmTransaction_PB_clicked();  // Slot for handling confirm transaction button click

    void on_UserTransferAmount_PB_clicked();  // Slot for handling transfer amount button click

    void on_UserTransfer_PB_clicked();  // Slot for handling transfer button click

    void on_UserTransfer_Back_PB_clicked();  // Slot for handling back from transfer button click

    void on_UserTransfer_confirm_PB_clicked();  // Slot for handling confirm transfer button click

    void on_Admin_Logout_PB_clicked();  // Slot for handling admin logout button click

    void on_Admin_GetAccountNo_PB_clicked();  // Slot for handling admin get account number button click

    void on_Admin_ViewAcountBalance_PB_clicked();  // Slot for handling admin view account balance button click

    void on_Admin_ViewTransactionHistory_PB_clicked();  // Slot for handling admin view transaction history button click

    void on_Back_AdminViewHistory_PB_clicked();  // Slot for handling back from admin view history button click

    void on_Display_AdminViewHistory_PB_clicked();  // Slot for handling display admin view history button click

    void on_Back_AdminViewBankDatabase_PB_clicked();  // Slot for handling back from admin view bank database button click

    void on_Admin_ViewBankDatabase_PB_clicked();  // Slot for handling admin view bank database button click

    void on_Admin_CreateNewUser_PB_clicked();  // Slot for handling admin create new user button click

    void on_Back_AdminCreateUser_PB_clicked();  // Slot for handling back from admin create user button click

    void on_Confirm_AdminCreateUser_PB_clicked();  // Slot for handling confirm admin create user button click

    void on_Admin_DeleteUser_PB_clicked();  // Slot for handling admin delete user button click

    void on_Admin_UpdateUser_PB_clicked();  // Slot for handling admin update user button click

    void on_Confirm_AdminUpdateUser_PB_clicked();  // Slot for handling confirm admin update user button click

    void on_Back_AdminUpdateUser_PB_clicked();  // Slot for handling back from admin update user button click

    void on_checkBox_IP_stateChanged(int arg1);

    void on_checkBox_password_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;  // Pointer to the UI elements for the MainWindow
    MyClient client;  // Instance of MyClient for network communication
    QString client_username;  // String to store the client's username
    QString client_accountNumber;  // String to store the client's account number
    QString client_authority;  // String to store the client's authority level
};
#endif // MAINWINDOW_H
