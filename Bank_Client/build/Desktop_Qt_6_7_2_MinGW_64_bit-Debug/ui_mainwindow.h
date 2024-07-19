/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *Login_page;
    QWidget *page;
    QLineEdit *lineEdit_username;
    QPushButton *PB_Login;
    QLineEdit *leIP;
    QLineEdit *lePort;
    QLabel *pic2_userame;
    QLabel *pic3_password;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *pic1_bankLogo;
    QLineEdit *lineEdit_password;
    QWidget *page_3;
    QPushButton *UserGetAccountNo_PB;
    QPushButton *UserAccountBalance_PB;
    QPushButton *UserViewTransaction_PB_2;
    QPushButton *UserMakeTransaction_PB;
    QPushButton *UserTransferAmount_PB;
    QPushButton *UserLogout_PB;
    QLabel *Label_textUser;
    QLabel *label_27;
    QWidget *page_2;
    QTableWidget *transactionHistoryTable;
    QLineEdit *lineEdit_UserAccountNumber;
    QLabel *label_AccountNumber;
    QSpinBox *spinBox_UserCount;
    QLabel *label_Count;
    QPushButton *UserShowTransactin_PB;
    QPushButton *Back_PB;
    QLabel *label_33;
    QLabel *label_63;
    QWidget *page_4;
    QPushButton *UserConfirmTransaction_PB;
    QPushButton *UserBack_Transaction_PB;
    QLabel *label_AccountNumber_Transaction;
    QLineEdit *lineEdit_UserAccountNumber_Transaction;
    QComboBox *comboBox_UserTransactionType;
    QLabel *label_userTransactionType;
    QLineEdit *lineEdit_UserTransactionAmount;
    QLabel *label_UserTransactionAmount;
    QLabel *label_26;
    QLabel *label_64;
    QWidget *page_5;
    QPushButton *UserTransfer_confirm_PB;
    QPushButton *UserTransfer_Back_PB;
    QLineEdit *fromAccountNumberLineEdit;
    QLineEdit *toAccountNumberLineEdit;
    QLineEdit *transferAmountLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_32;
    QLabel *label_65;
    QWidget *page_6;
    QPushButton *Admin_GetAccountNo_PB;
    QPushButton *Admin_ViewAcountBalance_PB;
    QPushButton *Admin_ViewTransactionHistory_PB;
    QPushButton *Admin_ViewBankDatabase_PB;
    QPushButton *Admin_CreateNewUser_PB;
    QPushButton *Admin_DeleteUser_PB;
    QPushButton *Admin_UpdateUser_PB;
    QPushButton *Admin_Logout_PB;
    QLabel *label_24;
    QWidget *page_7;
    QTableWidget *Admin_transactionHistoryTable;
    QLineEdit *LineEdit_Admin_AccountNo_ViewHistory;
    QSpinBox *spinBox__Admin_Count_ViewHistory;
    QPushButton *Back_AdminViewHistory_PB;
    QPushButton *Display_AdminViewHistory_PB;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_28;
    QLabel *label_62;
    QWidget *page_8;
    QPushButton *Back_AdminViewBankDatabase_PB;
    QTableWidget *TW_AdminViewBankDatabase;
    QLabel *label_29;
    QLabel *label_61;
    QWidget *page_9;
    QLabel *label_5;
    QLineEdit *LE_CreatUser_FullName;
    QLabel *label_6;
    QLineEdit *LE_CreatUser_Age;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *LE_CreatUser_UserName;
    QLabel *label_10;
    QLineEdit *LE_CreatUser_Password;
    QLabel *label_11;
    QLineEdit *LE_CreatUser_Email;
    QLineEdit *LE_CreatUser_AccountNumber;
    QLabel *label_12;
    QPushButton *Back_AdminCreateUser_PB;
    QPushButton *Confirm_AdminCreateUser_PB;
    QLabel *label_30;
    QWidget *page_10;
    QPushButton *Back_AdminUpdateUser_PB;
    QPushButton *Confirm_AdminUpdateUser_PB;
    QLabel *label_13;
    QLineEdit *LE_UpdateUser_Email;
    QLabel *label_14;
    QLineEdit *LE_UpdateUser_FullName;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *LE_UpdateUser_Password;
    QLineEdit *LE_UpdateUser_AccountNumber;
    QLabel *label_18;
    QLineEdit *LE_UpdateUser_UserName;
    QLineEdit *LE_UpdateUser_Age;
    QLabel *label_19;
    QLabel *label_31;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(762, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Bank_.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Login_page = new QStackedWidget(centralwidget);
        Login_page->setObjectName("Login_page");
        Login_page->setGeometry(QRect(10, 10, 741, 431));
        Login_page->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:1 rgba(0, 145, 200, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 132, 162, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.0111732 rgba(255, 105, 142, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        lineEdit_username = new QLineEdit(page);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(40, 230, 211, 41));
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        PB_Login = new QPushButton(page);
        PB_Login->setObjectName("PB_Login");
        PB_Login->setGeometry(QRect(70, 340, 141, 41));
        PB_Login->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        leIP = new QLineEdit(page);
        leIP->setObjectName("leIP");
        leIP->setGeometry(QRect(260, 30, 141, 24));
        lePort = new QLineEdit(page);
        lePort->setObjectName("lePort");
        lePort->setGeometry(QRect(260, 60, 141, 24));
        pic2_userame = new QLabel(page);
        pic2_userame->setObjectName("pic2_userame");
        pic2_userame->setGeometry(QRect(0, 230, 31, 41));
        pic2_userame->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/OIP.png")));
        pic2_userame->setScaledContents(true);
        pic3_password = new QLabel(page);
        pic3_password->setObjectName("pic3_password");
        pic3_password->setGeometry(QRect(10, 290, 21, 31));
        pic3_password->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/password.png")));
        pic3_password->setScaledContents(true);
        label_20 = new QLabel(page);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(-10, 0, 761, 431));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/bankingCapture.PNG")));
        label_20->setScaledContents(true);
        label_21 = new QLabel(page);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(50, 110, 221, 61));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(66, 133, 199);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 22pt \"Segoe Print\";\n"
"font: 28pt \"Segoe UI\";\n"
"font: 900 35pt \"Segoe UI\";"));
        pic1_bankLogo = new QLabel(page);
        pic1_bankLogo->setObjectName("pic1_bankLogo");
        pic1_bankLogo->setGeometry(QRect(70, 50, 151, 161));
        pic1_bankLogo->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/images.ico")));
        pic1_bankLogo->setScaledContents(true);
        lineEdit_password = new QLineEdit(page);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(40, 280, 211, 41));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        Login_page->addWidget(page);
        label_20->raise();
        lineEdit_username->raise();
        PB_Login->raise();
        leIP->raise();
        lePort->raise();
        pic2_userame->raise();
        pic3_password->raise();
        label_21->raise();
        pic1_bankLogo->raise();
        lineEdit_password->raise();
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        UserGetAccountNo_PB = new QPushButton(page_3);
        UserGetAccountNo_PB->setObjectName("UserGetAccountNo_PB");
        UserGetAccountNo_PB->setGeometry(QRect(20, 80, 211, 61));
        UserGetAccountNo_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
""));
        UserAccountBalance_PB = new QPushButton(page_3);
        UserAccountBalance_PB->setObjectName("UserAccountBalance_PB");
        UserAccountBalance_PB->setGeometry(QRect(500, 80, 211, 61));
        UserAccountBalance_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
""));
        UserViewTransaction_PB_2 = new QPushButton(page_3);
        UserViewTransaction_PB_2->setObjectName("UserViewTransaction_PB_2");
        UserViewTransaction_PB_2->setGeometry(QRect(20, 210, 211, 61));
        UserViewTransaction_PB_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
""));
        UserMakeTransaction_PB = new QPushButton(page_3);
        UserMakeTransaction_PB->setObjectName("UserMakeTransaction_PB");
        UserMakeTransaction_PB->setGeometry(QRect(500, 210, 211, 61));
        UserMakeTransaction_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
""));
        UserTransferAmount_PB = new QPushButton(page_3);
        UserTransferAmount_PB->setObjectName("UserTransferAmount_PB");
        UserTransferAmount_PB->setGeometry(QRect(20, 330, 211, 61));
        UserTransferAmount_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
""));
        UserLogout_PB = new QPushButton(page_3);
        UserLogout_PB->setObjectName("UserLogout_PB");
        UserLogout_PB->setGeometry(QRect(520, 330, 151, 61));
        UserLogout_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
"\n"
"\n"
""));
        Label_textUser = new QLabel(page_3);
        Label_textUser->setObjectName("Label_textUser");
        Label_textUser->setGeometry(QRect(190, 20, 491, 51));
        Label_textUser->setStyleSheet(QString::fromUtf8("font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 60);\n"
""));
        label_27 = new QLabel(page_3);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(0, 0, 741, 431));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_27->setScaledContents(true);
        Login_page->addWidget(page_3);
        label_27->raise();
        UserViewTransaction_PB_2->raise();
        UserMakeTransaction_PB->raise();
        UserTransferAmount_PB->raise();
        UserLogout_PB->raise();
        Label_textUser->raise();
        UserAccountBalance_PB->raise();
        UserGetAccountNo_PB->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        transactionHistoryTable = new QTableWidget(page_2);
        transactionHistoryTable->setObjectName("transactionHistoryTable");
        transactionHistoryTable->setGeometry(QRect(290, 100, 441, 251));
        transactionHistoryTable->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        lineEdit_UserAccountNumber = new QLineEdit(page_2);
        lineEdit_UserAccountNumber->setObjectName("lineEdit_UserAccountNumber");
        lineEdit_UserAccountNumber->setGeometry(QRect(20, 150, 201, 41));
        lineEdit_UserAccountNumber->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_AccountNumber = new QLabel(page_2);
        label_AccountNumber->setObjectName("label_AccountNumber");
        label_AccountNumber->setGeometry(QRect(20, 110, 161, 21));
        label_AccountNumber->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        spinBox_UserCount = new QSpinBox(page_2);
        spinBox_UserCount->setObjectName("spinBox_UserCount");
        spinBox_UserCount->setGeometry(QRect(20, 250, 201, 41));
        spinBox_UserCount->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_Count = new QLabel(page_2);
        label_Count->setObjectName("label_Count");
        label_Count->setGeometry(QRect(20, 220, 161, 21));
        label_Count->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        UserShowTransactin_PB = new QPushButton(page_2);
        UserShowTransactin_PB->setObjectName("UserShowTransactin_PB");
        UserShowTransactin_PB->setGeometry(QRect(490, 360, 211, 51));
        UserShowTransactin_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
""));
        Back_PB = new QPushButton(page_2);
        Back_PB->setObjectName("Back_PB");
        Back_PB->setGeometry(QRect(20, 360, 211, 51));
        Back_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        label_33 = new QLabel(page_2);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(0, 0, 741, 431));
        label_33->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_33->setScaledContents(true);
        label_63 = new QLabel(page_2);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(180, 0, 441, 61));
        label_63->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        Login_page->addWidget(page_2);
        label_33->raise();
        transactionHistoryTable->raise();
        lineEdit_UserAccountNumber->raise();
        label_AccountNumber->raise();
        spinBox_UserCount->raise();
        label_Count->raise();
        UserShowTransactin_PB->raise();
        Back_PB->raise();
        label_63->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        UserConfirmTransaction_PB = new QPushButton(page_4);
        UserConfirmTransaction_PB->setObjectName("UserConfirmTransaction_PB");
        UserConfirmTransaction_PB->setGeometry(QRect(480, 340, 201, 61));
        UserConfirmTransaction_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 16pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        UserBack_Transaction_PB = new QPushButton(page_4);
        UserBack_Transaction_PB->setObjectName("UserBack_Transaction_PB");
        UserBack_Transaction_PB->setGeometry(QRect(60, 340, 201, 61));
        UserBack_Transaction_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        label_AccountNumber_Transaction = new QLabel(page_4);
        label_AccountNumber_Transaction->setObjectName("label_AccountNumber_Transaction");
        label_AccountNumber_Transaction->setGeometry(QRect(30, 90, 141, 21));
        label_AccountNumber_Transaction->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        lineEdit_UserAccountNumber_Transaction = new QLineEdit(page_4);
        lineEdit_UserAccountNumber_Transaction->setObjectName("lineEdit_UserAccountNumber_Transaction");
        lineEdit_UserAccountNumber_Transaction->setGeometry(QRect(30, 120, 261, 51));
        lineEdit_UserAccountNumber_Transaction->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        comboBox_UserTransactionType = new QComboBox(page_4);
        comboBox_UserTransactionType->setObjectName("comboBox_UserTransactionType");
        comboBox_UserTransactionType->setGeometry(QRect(260, 220, 261, 51));
        comboBox_UserTransactionType->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_userTransactionType = new QLabel(page_4);
        label_userTransactionType->setObjectName("label_userTransactionType");
        label_userTransactionType->setGeometry(QRect(260, 200, 151, 21));
        label_userTransactionType->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        lineEdit_UserTransactionAmount = new QLineEdit(page_4);
        lineEdit_UserTransactionAmount->setObjectName("lineEdit_UserTransactionAmount");
        lineEdit_UserTransactionAmount->setGeometry(QRect(460, 120, 261, 51));
        lineEdit_UserTransactionAmount->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        label_UserTransactionAmount = new QLabel(page_4);
        label_UserTransactionAmount->setObjectName("label_UserTransactionAmount");
        label_UserTransactionAmount->setGeometry(QRect(460, 95, 171, 21));
        label_UserTransactionAmount->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_26 = new QLabel(page_4);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(0, 0, 741, 431));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_26->setScaledContents(true);
        label_64 = new QLabel(page_4);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(170, 10, 441, 61));
        label_64->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        Login_page->addWidget(page_4);
        label_26->raise();
        UserConfirmTransaction_PB->raise();
        UserBack_Transaction_PB->raise();
        label_AccountNumber_Transaction->raise();
        lineEdit_UserAccountNumber_Transaction->raise();
        comboBox_UserTransactionType->raise();
        label_userTransactionType->raise();
        lineEdit_UserTransactionAmount->raise();
        label_UserTransactionAmount->raise();
        label_64->raise();
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        UserTransfer_confirm_PB = new QPushButton(page_5);
        UserTransfer_confirm_PB->setObjectName("UserTransfer_confirm_PB");
        UserTransfer_confirm_PB->setGeometry(QRect(540, 330, 161, 51));
        UserTransfer_confirm_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 16pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        UserTransfer_Back_PB = new QPushButton(page_5);
        UserTransfer_Back_PB->setObjectName("UserTransfer_Back_PB");
        UserTransfer_Back_PB->setGeometry(QRect(50, 330, 161, 51));
        UserTransfer_Back_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        fromAccountNumberLineEdit = new QLineEdit(page_5);
        fromAccountNumberLineEdit->setObjectName("fromAccountNumberLineEdit");
        fromAccountNumberLineEdit->setGeometry(QRect(30, 110, 271, 51));
        fromAccountNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        toAccountNumberLineEdit = new QLineEdit(page_5);
        toAccountNumberLineEdit->setObjectName("toAccountNumberLineEdit");
        toAccountNumberLineEdit->setGeometry(QRect(450, 110, 271, 51));
        toAccountNumberLineEdit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        transferAmountLineEdit = new QLineEdit(page_5);
        transferAmountLineEdit->setObjectName("transferAmountLineEdit");
        transferAmountLineEdit->setGeometry(QRect(250, 220, 271, 51));
        transferAmountLineEdit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        label = new QLabel(page_5);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 90, 211, 16));
        label->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_2 = new QLabel(page_5);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 91, 161, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_3 = new QLabel(page_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 200, 161, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_32 = new QLabel(page_5);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(0, 0, 741, 431));
        label_32->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_32->setScaledContents(true);
        label_65 = new QLabel(page_5);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(240, -20, 441, 101));
        label_65->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        Login_page->addWidget(page_5);
        label_32->raise();
        UserTransfer_confirm_PB->raise();
        UserTransfer_Back_PB->raise();
        fromAccountNumberLineEdit->raise();
        toAccountNumberLineEdit->raise();
        transferAmountLineEdit->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_65->raise();
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        Admin_GetAccountNo_PB = new QPushButton(page_6);
        Admin_GetAccountNo_PB->setObjectName("Admin_GetAccountNo_PB");
        Admin_GetAccountNo_PB->setGeometry(QRect(120, 50, 151, 51));
        Admin_GetAccountNo_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_ViewAcountBalance_PB = new QPushButton(page_6);
        Admin_ViewAcountBalance_PB->setObjectName("Admin_ViewAcountBalance_PB");
        Admin_ViewAcountBalance_PB->setGeometry(QRect(330, 50, 161, 51));
        Admin_ViewAcountBalance_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_ViewTransactionHistory_PB = new QPushButton(page_6);
        Admin_ViewTransactionHistory_PB->setObjectName("Admin_ViewTransactionHistory_PB");
        Admin_ViewTransactionHistory_PB->setGeometry(QRect(530, 50, 171, 51));
        Admin_ViewTransactionHistory_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_ViewBankDatabase_PB = new QPushButton(page_6);
        Admin_ViewBankDatabase_PB->setObjectName("Admin_ViewBankDatabase_PB");
        Admin_ViewBankDatabase_PB->setGeometry(QRect(10, 190, 141, 61));
        Admin_ViewBankDatabase_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_CreateNewUser_PB = new QPushButton(page_6);
        Admin_CreateNewUser_PB->setObjectName("Admin_CreateNewUser_PB");
        Admin_CreateNewUser_PB->setGeometry(QRect(600, 190, 131, 71));
        Admin_CreateNewUser_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_DeleteUser_PB = new QPushButton(page_6);
        Admin_DeleteUser_PB->setObjectName("Admin_DeleteUser_PB");
        Admin_DeleteUser_PB->setGeometry(QRect(150, 370, 131, 51));
        Admin_DeleteUser_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_UpdateUser_PB = new QPushButton(page_6);
        Admin_UpdateUser_PB->setObjectName("Admin_UpdateUser_PB");
        Admin_UpdateUser_PB->setGeometry(QRect(320, 370, 141, 51));
        Admin_UpdateUser_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        Admin_Logout_PB = new QPushButton(page_6);
        Admin_Logout_PB->setObjectName("Admin_Logout_PB");
        Admin_Logout_PB->setGeometry(QRect(480, 370, 131, 51));
        Admin_Logout_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        label_24 = new QLabel(page_6);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(100, 100, 531, 301));
        label_24->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/services1.png")));
        label_24->setScaledContents(true);
        Login_page->addWidget(page_6);
        label_24->raise();
        Admin_GetAccountNo_PB->raise();
        Admin_ViewAcountBalance_PB->raise();
        Admin_ViewTransactionHistory_PB->raise();
        Admin_ViewBankDatabase_PB->raise();
        Admin_CreateNewUser_PB->raise();
        Admin_DeleteUser_PB->raise();
        Admin_UpdateUser_PB->raise();
        Admin_Logout_PB->raise();
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        Admin_transactionHistoryTable = new QTableWidget(page_7);
        Admin_transactionHistoryTable->setObjectName("Admin_transactionHistoryTable");
        Admin_transactionHistoryTable->setGeometry(QRect(430, 90, 291, 221));
        Admin_transactionHistoryTable->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        LineEdit_Admin_AccountNo_ViewHistory = new QLineEdit(page_7);
        LineEdit_Admin_AccountNo_ViewHistory->setObjectName("LineEdit_Admin_AccountNo_ViewHistory");
        LineEdit_Admin_AccountNo_ViewHistory->setGeometry(QRect(15, 140, 201, 41));
        LineEdit_Admin_AccountNo_ViewHistory->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        spinBox__Admin_Count_ViewHistory = new QSpinBox(page_7);
        spinBox__Admin_Count_ViewHistory->setObjectName("spinBox__Admin_Count_ViewHistory");
        spinBox__Admin_Count_ViewHistory->setGeometry(QRect(15, 240, 191, 41));
        spinBox__Admin_Count_ViewHistory->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgb(74, 92, 255);\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";"));
        Back_AdminViewHistory_PB = new QPushButton(page_7);
        Back_AdminViewHistory_PB->setObjectName("Back_AdminViewHistory_PB");
        Back_AdminViewHistory_PB->setGeometry(QRect(20, 340, 201, 61));
        Back_AdminViewHistory_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        Display_AdminViewHistory_PB = new QPushButton(page_7);
        Display_AdminViewHistory_PB->setObjectName("Display_AdminViewHistory_PB");
        Display_AdminViewHistory_PB->setGeometry(QRect(490, 340, 211, 61));
        Display_AdminViewHistory_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 16pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        label_4 = new QLabel(page_7);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(15, 110, 211, 21));
        label_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_9 = new QLabel(page_7);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(15, 210, 131, 21));
        label_9->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_28 = new QLabel(page_7);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(0, 0, 741, 431));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_28->setScaledContents(true);
        label_62 = new QLabel(page_7);
        label_62->setObjectName("label_62");
        label_62->setGeometry(QRect(150, 10, 441, 61));
        label_62->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        Login_page->addWidget(page_7);
        label_28->raise();
        Admin_transactionHistoryTable->raise();
        LineEdit_Admin_AccountNo_ViewHistory->raise();
        spinBox__Admin_Count_ViewHistory->raise();
        Back_AdminViewHistory_PB->raise();
        Display_AdminViewHistory_PB->raise();
        label_4->raise();
        label_9->raise();
        label_62->raise();
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        Back_AdminViewBankDatabase_PB = new QPushButton(page_8);
        Back_AdminViewBankDatabase_PB->setObjectName("Back_AdminViewBankDatabase_PB");
        Back_AdminViewBankDatabase_PB->setGeometry(QRect(229, 383, 281, 41));
        Back_AdminViewBankDatabase_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        TW_AdminViewBankDatabase = new QTableWidget(page_8);
        TW_AdminViewBankDatabase->setObjectName("TW_AdminViewBankDatabase");
        TW_AdminViewBankDatabase->setGeometry(QRect(10, 70, 721, 311));
        TW_AdminViewBankDatabase->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        label_29 = new QLabel(page_8);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(0, 0, 741, 431));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_29->setScaledContents(true);
        label_61 = new QLabel(page_8);
        label_61->setObjectName("label_61");
        label_61->setGeometry(QRect(200, 10, 401, 51));
        label_61->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        Login_page->addWidget(page_8);
        label_29->raise();
        Back_AdminViewBankDatabase_PB->raise();
        TW_AdminViewBankDatabase->raise();
        label_61->raise();
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_5 = new QLabel(page_9);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 10, 401, 51));
        label_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        LE_CreatUser_FullName = new QLineEdit(page_9);
        LE_CreatUser_FullName->setObjectName("LE_CreatUser_FullName");
        LE_CreatUser_FullName->setGeometry(QRect(20, 110, 281, 41));
        LE_CreatUser_FullName->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_6 = new QLabel(page_9);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 80, 91, 21));
        label_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_CreatUser_Age = new QLineEdit(page_9);
        LE_CreatUser_Age->setObjectName("LE_CreatUser_Age");
        LE_CreatUser_Age->setGeometry(QRect(440, 110, 281, 41));
        LE_CreatUser_Age->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_7 = new QLabel(page_9);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 80, 71, 21));
        label_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_8 = new QLabel(page_9);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 170, 91, 21));
        label_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_CreatUser_UserName = new QLineEdit(page_9);
        LE_CreatUser_UserName->setObjectName("LE_CreatUser_UserName");
        LE_CreatUser_UserName->setGeometry(QRect(20, 200, 281, 41));
        LE_CreatUser_UserName->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_10 = new QLabel(page_9);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(440, 170, 71, 21));
        label_10->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_CreatUser_Password = new QLineEdit(page_9);
        LE_CreatUser_Password->setObjectName("LE_CreatUser_Password");
        LE_CreatUser_Password->setGeometry(QRect(440, 200, 281, 41));
        LE_CreatUser_Password->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_11 = new QLabel(page_9);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 260, 71, 21));
        label_11->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_CreatUser_Email = new QLineEdit(page_9);
        LE_CreatUser_Email->setObjectName("LE_CreatUser_Email");
        LE_CreatUser_Email->setGeometry(QRect(20, 290, 281, 41));
        LE_CreatUser_Email->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        LE_CreatUser_AccountNumber = new QLineEdit(page_9);
        LE_CreatUser_AccountNumber->setObjectName("LE_CreatUser_AccountNumber");
        LE_CreatUser_AccountNumber->setGeometry(QRect(440, 290, 281, 41));
        LE_CreatUser_AccountNumber->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_12 = new QLabel(page_9);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(440, 260, 111, 21));
        label_12->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        Back_AdminCreateUser_PB = new QPushButton(page_9);
        Back_AdminCreateUser_PB->setObjectName("Back_AdminCreateUser_PB");
        Back_AdminCreateUser_PB->setGeometry(QRect(9, 360, 161, 51));
        Back_AdminCreateUser_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        Confirm_AdminCreateUser_PB = new QPushButton(page_9);
        Confirm_AdminCreateUser_PB->setObjectName("Confirm_AdminCreateUser_PB");
        Confirm_AdminCreateUser_PB->setGeometry(QRect(520, 360, 181, 51));
        Confirm_AdminCreateUser_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 16pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        label_30 = new QLabel(page_9);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(0, 0, 741, 431));
        label_30->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_30->setScaledContents(true);
        Login_page->addWidget(page_9);
        label_30->raise();
        label_5->raise();
        LE_CreatUser_FullName->raise();
        label_6->raise();
        LE_CreatUser_Age->raise();
        label_7->raise();
        label_8->raise();
        LE_CreatUser_UserName->raise();
        label_10->raise();
        LE_CreatUser_Password->raise();
        label_11->raise();
        LE_CreatUser_Email->raise();
        LE_CreatUser_AccountNumber->raise();
        label_12->raise();
        Back_AdminCreateUser_PB->raise();
        Confirm_AdminCreateUser_PB->raise();
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        Back_AdminUpdateUser_PB = new QPushButton(page_10);
        Back_AdminUpdateUser_PB->setObjectName("Back_AdminUpdateUser_PB");
        Back_AdminUpdateUser_PB->setGeometry(QRect(30, 350, 151, 51));
        Back_AdminUpdateUser_PB->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 16pt \"Segoe UI\";\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.463687 rgba(255, 62, 110, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0.748687, y1:0.165, x2:1, y2:0, stop:0 rgba(255, 59, 88, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(74, 92, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(255, 95, 119, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
""));
        Confirm_AdminUpdateUser_PB = new QPushButton(page_10);
        Confirm_AdminUpdateUser_PB->setObjectName("Confirm_AdminUpdateUser_PB");
        Confirm_AdminUpdateUser_PB->setGeometry(QRect(550, 350, 151, 51));
        Confirm_AdminUpdateUser_PB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-width: 2px;\n"
"    border-radius: 15px;\n"
"    padding: 5px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.96648, y2:1, stop:1 rgba(11, 9, 84, 255));\n"
"color: rgb(255, 170, 0);\n"
"\n"
"font: 700 16pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"};\n"
"\n"
""));
        label_13 = new QLabel(page_10);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(440, 250, 121, 21));
        label_13->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_UpdateUser_Email = new QLineEdit(page_10);
        LE_UpdateUser_Email->setObjectName("LE_UpdateUser_Email");
        LE_UpdateUser_Email->setGeometry(QRect(20, 280, 281, 41));
        LE_UpdateUser_Email->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_14 = new QLabel(page_10);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(230, 0, 411, 61));
        label_14->setStyleSheet(QString::fromUtf8("\n"
"font: 28pt \"Symbol\";\n"
"\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));\n"
"\n"
"font: 700 italic 36pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 100);\n"
""));
        LE_UpdateUser_FullName = new QLineEdit(page_10);
        LE_UpdateUser_FullName->setObjectName("LE_UpdateUser_FullName");
        LE_UpdateUser_FullName->setGeometry(QRect(20, 100, 281, 41));
        LE_UpdateUser_FullName->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_15 = new QLabel(page_10);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 70, 71, 21));
        label_15->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_16 = new QLabel(page_10);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 160, 71, 21));
        label_16->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_17 = new QLabel(page_10);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(440, 160, 71, 21));
        label_17->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_UpdateUser_Password = new QLineEdit(page_10);
        LE_UpdateUser_Password->setObjectName("LE_UpdateUser_Password");
        LE_UpdateUser_Password->setGeometry(QRect(440, 190, 281, 41));
        LE_UpdateUser_Password->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        LE_UpdateUser_AccountNumber = new QLineEdit(page_10);
        LE_UpdateUser_AccountNumber->setObjectName("LE_UpdateUser_AccountNumber");
        LE_UpdateUser_AccountNumber->setGeometry(QRect(440, 280, 281, 41));
        LE_UpdateUser_AccountNumber->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_18 = new QLabel(page_10);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(440, 70, 71, 21));
        label_18->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        LE_UpdateUser_UserName = new QLineEdit(page_10);
        LE_UpdateUser_UserName->setObjectName("LE_UpdateUser_UserName");
        LE_UpdateUser_UserName->setGeometry(QRect(20, 190, 281, 41));
        LE_UpdateUser_UserName->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        LE_UpdateUser_Age = new QLineEdit(page_10);
        LE_UpdateUser_Age->setObjectName("LE_UpdateUser_Age");
        LE_UpdateUser_Age->setGeometry(QRect(440, 100, 281, 41));
        LE_UpdateUser_Age->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        label_19 = new QLabel(page_10);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 250, 71, 21));
        label_19->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:1, y1:0.017, x2:1, y2:0, stop:0 rgba(32, 110, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));
        label_31 = new QLabel(page_10);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(0, 0, 741, 431));
        label_31->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/pink-sky-horizon-scenic-flying-birds-seascape-sunset-2560x1440-4586.jpg")));
        label_31->setScaledContents(true);
        Login_page->addWidget(page_10);
        label_31->raise();
        Back_AdminUpdateUser_PB->raise();
        Confirm_AdminUpdateUser_PB->raise();
        label_13->raise();
        LE_UpdateUser_Email->raise();
        label_14->raise();
        LE_UpdateUser_FullName->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        LE_UpdateUser_Password->raise();
        LE_UpdateUser_AccountNumber->raise();
        label_18->raise();
        LE_UpdateUser_UserName->raise();
        LE_UpdateUser_Age->raise();
        label_19->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 762, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Login_page->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bank System", nullptr));
        PB_Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        pic2_userame->setText(QString());
        pic3_password->setText(QString());
        label_20->setText(QString());
        label_21->setText(QString());
        pic1_bankLogo->setText(QString());
        UserGetAccountNo_PB->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        UserAccountBalance_PB->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        UserViewTransaction_PB_2->setText(QCoreApplication::translate("MainWindow", "View Account Transaction", nullptr));
        UserMakeTransaction_PB->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        UserTransferAmount_PB->setText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
        UserLogout_PB->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        Label_textUser->setText(QString());
        label_27->setText(QString());
        label_AccountNumber->setText(QCoreApplication::translate("MainWindow", "Account Number", nullptr));
        label_Count->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        UserShowTransactin_PB->setText(QCoreApplication::translate("MainWindow", "ShowResult", nullptr));
        Back_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_33->setText(QString());
        label_63->setText(QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        UserConfirmTransaction_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        UserBack_Transaction_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_AccountNumber_Transaction->setText(QCoreApplication::translate("MainWindow", "Account Number", nullptr));
        label_userTransactionType->setText(QCoreApplication::translate("MainWindow", "Transaction Type", nullptr));
        label_UserTransactionAmount->setText(QCoreApplication::translate("MainWindow", "Transaction Amount", nullptr));
        label_26->setText(QString());
        label_64->setText(QCoreApplication::translate("MainWindow", "Make Transaction ", nullptr));
        UserTransfer_confirm_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        UserTransfer_Back_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "From Account Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "To Account Number", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
        label_32->setText(QString());
        label_65->setText(QCoreApplication::translate("MainWindow", "Make Transfer", nullptr));
        Admin_GetAccountNo_PB->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        Admin_ViewAcountBalance_PB->setText(QCoreApplication::translate("MainWindow", "View Acount Balance", nullptr));
        Admin_ViewTransactionHistory_PB->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        Admin_ViewBankDatabase_PB->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        Admin_CreateNewUser_PB->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        Admin_DeleteUser_PB->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        Admin_UpdateUser_PB->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        Admin_Logout_PB->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        label_24->setText(QString());
        Back_AdminViewHistory_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Display_AdminViewHistory_PB->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter Account Number", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        label_28->setText(QString());
        label_62->setText(QCoreApplication::translate("MainWindow", "Transaction History", nullptr));
        Back_AdminViewBankDatabase_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_29->setText(QString());
        label_61->setText(QCoreApplication::translate("MainWindow", "Bank DataBase", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Account number", nullptr));
        Back_AdminCreateUser_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Confirm_AdminCreateUser_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_30->setText(QString());
        Back_AdminUpdateUser_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Confirm_AdminUpdateUser_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Account number", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_31->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
