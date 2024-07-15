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
    QLabel *pic2_userame;
    QLabel *pic3_password;
    QLabel *pic1_bankLogo;
    QWidget *page_3;
    QPushButton *UserGetAccountNo_PB;
    QPushButton *UserAccountBalance_PB;
    QPushButton *UserViewTransaction_PB_2;
    QPushButton *UserMakeTransaction_PB;
    QPushButton *UserTransferAmount_PB;
    QPushButton *UserLogout_PB;
    QLabel *Label_textUser;
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
    QWidget *page_6;
    QPushButton *Admin_GetAccountNo_PB;
    QPushButton *Admin_ViewAcountBalance_PB;
    QPushButton *Admin_ViewTransactionHistory_PB;
    QPushButton *Admin_ViewBankDatabase_PB;
    QPushButton *Admin_CreateNewUser_PB;
    QPushButton *Admin_DeleteUser_PB;
    QPushButton *Admin_UpdateUser_PB;
    QPushButton *Admin_Logout_PB;
    QWidget *page_7;
    QTableWidget *Admin_transactionHistoryTable;
    QLineEdit *LineEdit_Admin_AccountNo_ViewHistory;
    QSpinBox *spinBox__Admin_Count_ViewHistory;
    QPushButton *Back_AdminViewHistory_PB;
    QPushButton *Display_AdminViewHistory_PB;
    QLabel *label_4;
    QLabel *label_9;
    QWidget *page_8;
    QPushButton *Back_AdminViewBankDatabase_PB;
    QTableWidget *TW_AdminViewBankDatabase;
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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(762, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Login_page = new QStackedWidget(centralwidget);
        Login_page->setObjectName("Login_page");
        Login_page->setGeometry(QRect(10, 10, 741, 431));
        Login_page->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        lineEdit_username = new QLineEdit(page);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(470, 250, 181, 41));
        lineEdit_password = new QLineEdit(page);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(470, 310, 181, 41));
        PB_Login = new QPushButton(page);
        PB_Login->setObjectName("PB_Login");
        PB_Login->setGeometry(QRect(510, 370, 91, 31));
        PB_Login->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        leIP = new QLineEdit(page);
        leIP->setObjectName("leIP");
        leIP->setGeometry(QRect(20, 350, 141, 24));
        lePort = new QLineEdit(page);
        lePort->setObjectName("lePort");
        lePort->setGeometry(QRect(20, 380, 141, 24));
        pic2_userame = new QLabel(page);
        pic2_userame->setObjectName("pic2_userame");
        pic2_userame->setGeometry(QRect(430, 250, 31, 41));
        pic2_userame->setPixmap(QPixmap(QString::fromUtf8("../../OIP.png")));
        pic2_userame->setScaledContents(true);
        pic3_password = new QLabel(page);
        pic3_password->setObjectName("pic3_password");
        pic3_password->setGeometry(QRect(440, 310, 21, 31));
        pic3_password->setPixmap(QPixmap(QString::fromUtf8("../../password.png")));
        pic3_password->setScaledContents(true);
        pic1_bankLogo = new QLabel(page);
        pic1_bankLogo->setObjectName("pic1_bankLogo");
        pic1_bankLogo->setGeometry(QRect(460, 50, 191, 181));
        pic1_bankLogo->setPixmap(QPixmap(QString::fromUtf8("../../images-removebg-preview.png")));
        pic1_bankLogo->setScaledContents(true);
        Login_page->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        UserGetAccountNo_PB = new QPushButton(page_3);
        UserGetAccountNo_PB->setObjectName("UserGetAccountNo_PB");
        UserGetAccountNo_PB->setGeometry(QRect(40, 130, 151, 51));
        UserAccountBalance_PB = new QPushButton(page_3);
        UserAccountBalance_PB->setObjectName("UserAccountBalance_PB");
        UserAccountBalance_PB->setGeometry(QRect(530, 130, 151, 51));
        UserViewTransaction_PB_2 = new QPushButton(page_3);
        UserViewTransaction_PB_2->setObjectName("UserViewTransaction_PB_2");
        UserViewTransaction_PB_2->setGeometry(QRect(40, 230, 151, 51));
        UserMakeTransaction_PB = new QPushButton(page_3);
        UserMakeTransaction_PB->setObjectName("UserMakeTransaction_PB");
        UserMakeTransaction_PB->setGeometry(QRect(530, 230, 151, 51));
        UserTransferAmount_PB = new QPushButton(page_3);
        UserTransferAmount_PB->setObjectName("UserTransferAmount_PB");
        UserTransferAmount_PB->setGeometry(QRect(40, 330, 151, 51));
        UserLogout_PB = new QPushButton(page_3);
        UserLogout_PB->setObjectName("UserLogout_PB");
        UserLogout_PB->setGeometry(QRect(530, 330, 151, 51));
        Label_textUser = new QLabel(page_3);
        Label_textUser->setObjectName("Label_textUser");
        Label_textUser->setGeometry(QRect(130, 20, 491, 31));
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
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        Admin_GetAccountNo_PB = new QPushButton(page_6);
        Admin_GetAccountNo_PB->setObjectName("Admin_GetAccountNo_PB");
        Admin_GetAccountNo_PB->setGeometry(QRect(60, 40, 141, 31));
        Admin_ViewAcountBalance_PB = new QPushButton(page_6);
        Admin_ViewAcountBalance_PB->setObjectName("Admin_ViewAcountBalance_PB");
        Admin_ViewAcountBalance_PB->setGeometry(QRect(300, 40, 141, 31));
        Admin_ViewTransactionHistory_PB = new QPushButton(page_6);
        Admin_ViewTransactionHistory_PB->setObjectName("Admin_ViewTransactionHistory_PB");
        Admin_ViewTransactionHistory_PB->setGeometry(QRect(500, 40, 141, 31));
        Admin_ViewBankDatabase_PB = new QPushButton(page_6);
        Admin_ViewBankDatabase_PB->setObjectName("Admin_ViewBankDatabase_PB");
        Admin_ViewBankDatabase_PB->setGeometry(QRect(170, 120, 151, 31));
        Admin_CreateNewUser_PB = new QPushButton(page_6);
        Admin_CreateNewUser_PB->setObjectName("Admin_CreateNewUser_PB");
        Admin_CreateNewUser_PB->setGeometry(QRect(440, 120, 101, 31));
        Admin_DeleteUser_PB = new QPushButton(page_6);
        Admin_DeleteUser_PB->setObjectName("Admin_DeleteUser_PB");
        Admin_DeleteUser_PB->setGeometry(QRect(60, 200, 101, 31));
        Admin_UpdateUser_PB = new QPushButton(page_6);
        Admin_UpdateUser_PB->setObjectName("Admin_UpdateUser_PB");
        Admin_UpdateUser_PB->setGeometry(QRect(530, 200, 101, 31));
        Admin_Logout_PB = new QPushButton(page_6);
        Admin_Logout_PB->setObjectName("Admin_Logout_PB");
        Admin_Logout_PB->setGeometry(QRect(270, 310, 101, 31));
        Login_page->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        Admin_transactionHistoryTable = new QTableWidget(page_7);
        Admin_transactionHistoryTable->setObjectName("Admin_transactionHistoryTable");
        Admin_transactionHistoryTable->setGeometry(QRect(405, 30, 291, 221));
        LineEdit_Admin_AccountNo_ViewHistory = new QLineEdit(page_7);
        LineEdit_Admin_AccountNo_ViewHistory->setObjectName("LineEdit_Admin_AccountNo_ViewHistory");
        LineEdit_Admin_AccountNo_ViewHistory->setGeometry(QRect(20, 60, 181, 31));
        spinBox__Admin_Count_ViewHistory = new QSpinBox(page_7);
        spinBox__Admin_Count_ViewHistory->setObjectName("spinBox__Admin_Count_ViewHistory");
        spinBox__Admin_Count_ViewHistory->setGeometry(QRect(20, 130, 181, 31));
        Back_AdminViewHistory_PB = new QPushButton(page_7);
        Back_AdminViewHistory_PB->setObjectName("Back_AdminViewHistory_PB");
        Back_AdminViewHistory_PB->setGeometry(QRect(40, 360, 131, 31));
        Display_AdminViewHistory_PB = new QPushButton(page_7);
        Display_AdminViewHistory_PB->setObjectName("Display_AdminViewHistory_PB");
        Display_AdminViewHistory_PB->setGeometry(QRect(380, 360, 111, 31));
        label_4 = new QLabel(page_7);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 30, 131, 21));
        label_9 = new QLabel(page_7);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 100, 131, 21));
        Login_page->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        Back_AdminViewBankDatabase_PB = new QPushButton(page_8);
        Back_AdminViewBankDatabase_PB->setObjectName("Back_AdminViewBankDatabase_PB");
        Back_AdminViewBankDatabase_PB->setGeometry(QRect(229, 383, 281, 41));
        TW_AdminViewBankDatabase = new QTableWidget(page_8);
        TW_AdminViewBankDatabase->setObjectName("TW_AdminViewBankDatabase");
        TW_AdminViewBankDatabase->setGeometry(QRect(10, 20, 711, 361));
        Login_page->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_5 = new QLabel(page_9);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 10, 131, 21));
        LE_CreatUser_FullName = new QLineEdit(page_9);
        LE_CreatUser_FullName->setObjectName("LE_CreatUser_FullName");
        LE_CreatUser_FullName->setGeometry(QRect(10, 80, 281, 24));
        label_6 = new QLabel(page_9);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 50, 71, 21));
        LE_CreatUser_Age = new QLineEdit(page_9);
        LE_CreatUser_Age->setObjectName("LE_CreatUser_Age");
        LE_CreatUser_Age->setGeometry(QRect(430, 80, 281, 24));
        label_7 = new QLabel(page_9);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(430, 50, 71, 21));
        label_8 = new QLabel(page_9);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 140, 71, 21));
        LE_CreatUser_UserName = new QLineEdit(page_9);
        LE_CreatUser_UserName->setObjectName("LE_CreatUser_UserName");
        LE_CreatUser_UserName->setGeometry(QRect(10, 170, 281, 24));
        label_10 = new QLabel(page_9);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(430, 140, 71, 21));
        LE_CreatUser_Password = new QLineEdit(page_9);
        LE_CreatUser_Password->setObjectName("LE_CreatUser_Password");
        LE_CreatUser_Password->setGeometry(QRect(430, 170, 281, 24));
        label_11 = new QLabel(page_9);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 230, 71, 21));
        LE_CreatUser_Email = new QLineEdit(page_9);
        LE_CreatUser_Email->setObjectName("LE_CreatUser_Email");
        LE_CreatUser_Email->setGeometry(QRect(10, 260, 281, 24));
        LE_CreatUser_AccountNumber = new QLineEdit(page_9);
        LE_CreatUser_AccountNumber->setObjectName("LE_CreatUser_AccountNumber");
        LE_CreatUser_AccountNumber->setGeometry(QRect(430, 260, 281, 24));
        label_12 = new QLabel(page_9);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(430, 230, 111, 21));
        Back_AdminCreateUser_PB = new QPushButton(page_9);
        Back_AdminCreateUser_PB->setObjectName("Back_AdminCreateUser_PB");
        Back_AdminCreateUser_PB->setGeometry(QRect(70, 360, 80, 24));
        Confirm_AdminCreateUser_PB = new QPushButton(page_9);
        Confirm_AdminCreateUser_PB->setObjectName("Confirm_AdminCreateUser_PB");
        Confirm_AdminCreateUser_PB->setGeometry(QRect(450, 360, 80, 24));
        Login_page->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        Back_AdminUpdateUser_PB = new QPushButton(page_10);
        Back_AdminUpdateUser_PB->setObjectName("Back_AdminUpdateUser_PB");
        Back_AdminUpdateUser_PB->setGeometry(QRect(70, 370, 80, 24));
        Confirm_AdminUpdateUser_PB = new QPushButton(page_10);
        Confirm_AdminUpdateUser_PB->setObjectName("Confirm_AdminUpdateUser_PB");
        Confirm_AdminUpdateUser_PB->setGeometry(QRect(410, 370, 80, 24));
        label_13 = new QLabel(page_10);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(440, 240, 111, 21));
        LE_UpdateUser_Email = new QLineEdit(page_10);
        LE_UpdateUser_Email->setObjectName("LE_UpdateUser_Email");
        LE_UpdateUser_Email->setGeometry(QRect(20, 270, 281, 24));
        label_14 = new QLabel(page_10);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 20, 131, 21));
        LE_UpdateUser_FullName = new QLineEdit(page_10);
        LE_UpdateUser_FullName->setObjectName("LE_UpdateUser_FullName");
        LE_UpdateUser_FullName->setGeometry(QRect(20, 90, 281, 24));
        label_15 = new QLabel(page_10);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 60, 71, 21));
        label_16 = new QLabel(page_10);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 150, 71, 21));
        label_17 = new QLabel(page_10);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(440, 150, 71, 21));
        LE_UpdateUser_Password = new QLineEdit(page_10);
        LE_UpdateUser_Password->setObjectName("LE_UpdateUser_Password");
        LE_UpdateUser_Password->setGeometry(QRect(440, 180, 281, 24));
        LE_UpdateUser_AccountNumber = new QLineEdit(page_10);
        LE_UpdateUser_AccountNumber->setObjectName("LE_UpdateUser_AccountNumber");
        LE_UpdateUser_AccountNumber->setGeometry(QRect(440, 270, 281, 24));
        label_18 = new QLabel(page_10);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(440, 60, 71, 21));
        LE_UpdateUser_UserName = new QLineEdit(page_10);
        LE_UpdateUser_UserName->setObjectName("LE_UpdateUser_UserName");
        LE_UpdateUser_UserName->setGeometry(QRect(20, 180, 281, 24));
        LE_UpdateUser_Age = new QLineEdit(page_10);
        LE_UpdateUser_Age->setObjectName("LE_UpdateUser_Age");
        LE_UpdateUser_Age->setGeometry(QRect(440, 90, 281, 24));
        label_19 = new QLabel(page_10);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 240, 71, 21));
        Login_page->addWidget(page_10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 762, 21));
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
        pic2_userame->setText(QString());
        pic3_password->setText(QString());
        pic1_bankLogo->setText(QString());
        UserGetAccountNo_PB->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        UserAccountBalance_PB->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        UserViewTransaction_PB_2->setText(QCoreApplication::translate("MainWindow", "View Account Transaction", nullptr));
        UserMakeTransaction_PB->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        UserTransferAmount_PB->setText(QCoreApplication::translate("MainWindow", "Transfer Amount", nullptr));
        UserLogout_PB->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        Label_textUser->setText(QString());
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
        Admin_GetAccountNo_PB->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        Admin_ViewAcountBalance_PB->setText(QCoreApplication::translate("MainWindow", "View Acount Balance", nullptr));
        Admin_ViewTransactionHistory_PB->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        Admin_ViewBankDatabase_PB->setText(QCoreApplication::translate("MainWindow", "View Bank Database", nullptr));
        Admin_CreateNewUser_PB->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        Admin_DeleteUser_PB->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        Admin_UpdateUser_PB->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        Admin_Logout_PB->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        Back_AdminViewHistory_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Display_AdminViewHistory_PB->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Enter Account Number", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        Back_AdminViewBankDatabase_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Account number", nullptr));
        Back_AdminCreateUser_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Confirm_AdminCreateUser_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        Back_AdminUpdateUser_PB->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Confirm_AdminUpdateUser_PB->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Account number", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
