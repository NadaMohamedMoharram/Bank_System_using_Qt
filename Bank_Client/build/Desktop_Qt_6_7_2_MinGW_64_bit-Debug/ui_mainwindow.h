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
    QLineEdit *lineEdit_password;
    QPushButton *PB_Login;
    QLineEdit *leIP;
    QLineEdit *lePort;
    QWidget *page_3;
    QPushButton *UserGetAccountNo_PB;
    QPushButton *UserAccountBalance_PB;
    QPushButton *UserViewTransaction_PB_2;
    QPushButton *UserMakeTransaction_PB;
    QPushButton *UserTransferAmount_PB;
    QPushButton *UserLogout_PB;
    QWidget *page_2;
    QTableWidget *transactionHistoryTable;
    QLineEdit *lineEdit_UserAccountNumber;
    QLabel *label_AccountNumber;
    QSpinBox *spinBox_UserCount;
    QLabel *label_Count;
    QPushButton *UserShowTransactin_PB;
    QPushButton *Back_PB;
    QWidget *page_4;
    QPushButton *UserConfirmTransaction_PB;
    QPushButton *UserBack_Transaction_PB;
    QLabel *label_AccountNumber_Transaction;
    QLineEdit *lineEdit_UserAccountNumber_Transaction;
    QComboBox *comboBox_UserTransactionType;
    QLabel *label_userTransactionType;
    QLineEdit *lineEdit_UserTransactionAmount;
    QLabel *label_UserTransactionAmount;
    QWidget *page_5;
    QPushButton *UserTransfer_confirm_PB;
    QPushButton *UserTransfer_Back_PB;
    QLineEdit *fromAccountNumberLineEdit;
    QLineEdit *toAccountNumberLineEdit;
    QLineEdit *transferAmountLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Login_page = new QStackedWidget(centralwidget);
        Login_page->setObjectName("Login_page");
        Login_page->setGeometry(QRect(20, 10, 741, 421));
        Login_page->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        page = new QWidget();
        page->setObjectName("page");
        lineEdit_username = new QLineEdit(page);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(122, 30, 141, 24));
        lineEdit_password = new QLineEdit(page);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(120, 70, 141, 24));
        PB_Login = new QPushButton(page);
        PB_Login->setObjectName("PB_Login");
        PB_Login->setGeometry(QRect(150, 120, 80, 24));
        PB_Login->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        leIP = new QLineEdit(page);
        leIP->setObjectName("leIP");
        leIP->setGeometry(QRect(50, 170, 141, 24));
        lePort = new QLineEdit(page);
        lePort->setObjectName("lePort");
        lePort->setGeometry(QRect(50, 200, 141, 24));
        Login_page->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        UserGetAccountNo_PB = new QPushButton(page_3);
        UserGetAccountNo_PB->setObjectName("UserGetAccountNo_PB");
        UserGetAccountNo_PB->setGeometry(QRect(50, 30, 151, 51));
        UserAccountBalance_PB = new QPushButton(page_3);
        UserAccountBalance_PB->setObjectName("UserAccountBalance_PB");
        UserAccountBalance_PB->setGeometry(QRect(460, 30, 151, 51));
        UserViewTransaction_PB_2 = new QPushButton(page_3);
        UserViewTransaction_PB_2->setObjectName("UserViewTransaction_PB_2");
        UserViewTransaction_PB_2->setGeometry(QRect(50, 120, 151, 51));
        UserMakeTransaction_PB = new QPushButton(page_3);
        UserMakeTransaction_PB->setObjectName("UserMakeTransaction_PB");
        UserMakeTransaction_PB->setGeometry(QRect(460, 120, 151, 51));
        UserTransferAmount_PB = new QPushButton(page_3);
        UserTransferAmount_PB->setObjectName("UserTransferAmount_PB");
        UserTransferAmount_PB->setGeometry(QRect(50, 230, 151, 51));
        UserLogout_PB = new QPushButton(page_3);
        UserLogout_PB->setObjectName("UserLogout_PB");
        UserLogout_PB->setGeometry(QRect(460, 230, 151, 51));
        Login_page->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        transactionHistoryTable = new QTableWidget(page_2);
        transactionHistoryTable->setObjectName("transactionHistoryTable");
        transactionHistoryTable->setGeometry(QRect(270, 40, 441, 281));
        lineEdit_UserAccountNumber = new QLineEdit(page_2);
        lineEdit_UserAccountNumber->setObjectName("lineEdit_UserAccountNumber");
        lineEdit_UserAccountNumber->setGeometry(QRect(20, 60, 191, 31));
        label_AccountNumber = new QLabel(page_2);
        label_AccountNumber->setObjectName("label_AccountNumber");
        label_AccountNumber->setGeometry(QRect(20, 30, 161, 21));
        spinBox_UserCount = new QSpinBox(page_2);
        spinBox_UserCount->setObjectName("spinBox_UserCount");
        spinBox_UserCount->setGeometry(QRect(21, 150, 191, 25));
        label_Count = new QLabel(page_2);
        label_Count->setObjectName("label_Count");
        label_Count->setGeometry(QRect(10, 120, 161, 21));
        UserShowTransactin_PB = new QPushButton(page_2);
        UserShowTransactin_PB->setObjectName("UserShowTransactin_PB");
        UserShowTransactin_PB->setGeometry(QRect(380, 370, 171, 31));
        Back_PB = new QPushButton(page_2);
        Back_PB->setObjectName("Back_PB");
        Back_PB->setGeometry(QRect(30, 363, 151, 41));
        Login_page->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        UserConfirmTransaction_PB = new QPushButton(page_4);
        UserConfirmTransaction_PB->setObjectName("UserConfirmTransaction_PB");
        UserConfirmTransaction_PB->setGeometry(QRect(410, 313, 201, 61));
        UserBack_Transaction_PB = new QPushButton(page_4);
        UserBack_Transaction_PB->setObjectName("UserBack_Transaction_PB");
        UserBack_Transaction_PB->setGeometry(QRect(70, 310, 201, 61));
        label_AccountNumber_Transaction = new QLabel(page_4);
        label_AccountNumber_Transaction->setObjectName("label_AccountNumber_Transaction");
        label_AccountNumber_Transaction->setGeometry(QRect(30, 30, 161, 21));
        lineEdit_UserAccountNumber_Transaction = new QLineEdit(page_4);
        lineEdit_UserAccountNumber_Transaction->setObjectName("lineEdit_UserAccountNumber_Transaction");
        lineEdit_UserAccountNumber_Transaction->setGeometry(QRect(30, 60, 191, 31));
        comboBox_UserTransactionType = new QComboBox(page_4);
        comboBox_UserTransactionType->setObjectName("comboBox_UserTransactionType");
        comboBox_UserTransactionType->setGeometry(QRect(30, 210, 191, 31));
        label_userTransactionType = new QLabel(page_4);
        label_userTransactionType->setObjectName("label_userTransactionType");
        label_userTransactionType->setGeometry(QRect(30, 180, 91, 21));
        lineEdit_UserTransactionAmount = new QLineEdit(page_4);
        lineEdit_UserTransactionAmount->setObjectName("lineEdit_UserTransactionAmount");
        lineEdit_UserTransactionAmount->setGeometry(QRect(30, 140, 191, 31));
        label_UserTransactionAmount = new QLabel(page_4);
        label_UserTransactionAmount->setObjectName("label_UserTransactionAmount");
        label_UserTransactionAmount->setGeometry(QRect(30, 110, 141, 16));
        Login_page->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        UserTransfer_confirm_PB = new QPushButton(page_5);
        UserTransfer_confirm_PB->setObjectName("UserTransfer_confirm_PB");
        UserTransfer_confirm_PB->setGeometry(QRect(379, 323, 161, 51));
        UserTransfer_Back_PB = new QPushButton(page_5);
        UserTransfer_Back_PB->setObjectName("UserTransfer_Back_PB");
        UserTransfer_Back_PB->setGeometry(QRect(110, 320, 161, 51));
        fromAccountNumberLineEdit = new QLineEdit(page_5);
        fromAccountNumberLineEdit->setObjectName("fromAccountNumberLineEdit");
        fromAccountNumberLineEdit->setGeometry(QRect(80, 60, 161, 41));
        toAccountNumberLineEdit = new QLineEdit(page_5);
        toAccountNumberLineEdit->setObjectName("toAccountNumberLineEdit");
        toAccountNumberLineEdit->setGeometry(QRect(80, 130, 161, 41));
        transferAmountLineEdit = new QLineEdit(page_5);
        transferAmountLineEdit->setObjectName("transferAmountLineEdit");
        transferAmountLineEdit->setGeometry(QRect(80, 200, 161, 41));
        label = new QLabel(page_5);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 161, 16));
        label_2 = new QLabel(page_5);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 110, 161, 16));
        label_3 = new QLabel(page_5);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 180, 161, 16));
        Login_page->addWidget(page_5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Login_page->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PB_Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        UserGetAccountNo_PB->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        UserAccountBalance_PB->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        UserViewTransaction_PB_2->setText(QCoreApplication::translate("MainWindow", "View Account Transaction", nullptr));
        UserMakeTransaction_PB->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        UserTransferAmount_PB->setText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
        UserLogout_PB->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        label_AccountNumber->setText(QCoreApplication::translate("MainWindow", "Account Number", nullptr));
        label_Count->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        UserShowTransactin_PB->setText(QCoreApplication::translate("MainWindow", "ShowResult", nullptr));
        Back_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        UserConfirmTransaction_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        UserBack_Transaction_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_AccountNumber_Transaction->setText(QCoreApplication::translate("MainWindow", "Account Number", nullptr));
        label_userTransactionType->setText(QCoreApplication::translate("MainWindow", "Transaction Type", nullptr));
        label_UserTransactionAmount->setText(QCoreApplication::translate("MainWindow", "Transaction Amount", nullptr));
        UserTransfer_confirm_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        UserTransfer_Back_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "From Account Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "To Account Number", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
