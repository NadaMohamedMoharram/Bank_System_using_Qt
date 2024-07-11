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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
        Login_page->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Login_page->setCurrentIndex(1);


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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
