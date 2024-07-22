#include "database_class.h"

DataBase_Class::DataBase_Class(QObject *parent)
    : QObject{parent}
{
    FilePath{"D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\Database\\LoginDB.json"};
    initDataBase();
}

// DataBase_Class::DataBase(QObject *parent)
// {
//  initDataBase();
// }

void DataBase_Class::addObject(QString name, qint32 age)
{
    initDataBase();
    qint32 lastId = jsonDataBase.back()["ID"].toInt();
    QJsonObject newObj;
    newObj["ID"] = lastId +1;
    newObj["Name"] = name;
    newObj["Age"] = age;
    jsonDataBase.append(newObj);
    QJsonArray jsonArr;
    for(auto&vv : jsonDataBase)
    {
        jsonArr.append(vv);
    }
    QFile file(FilePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}

void DataBase_Class::updateObject(qint32 id, QString name, qint32 age)
{
    initDataBase();
    for(auto&vv:jsonDataBase)
    {
        if(vv["ID"].toInt() ==id)
        {
            vv["Name"] = name;
            vv["Age"] = age;
            break;
        }
    }
    QJsonArray jsonArr;
    for(auto&vv : jsonDataBase)
    {
        jsonArr.append(vv);
    }
    QFile file(FilePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}

void DataBase_Class::deleteObject(qint32 id)
{
    initDataBase();
    QJsonArray jsonArr;
    for(auto&vv:jsonDataBase)
    {
        if(vv["ID"].toInt() != id)
        {
            jsonArr.append(vv);
        }
    }
    QFile file(FilePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        file.write(QJsonDocument(jsonArr).toJson());
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}

void DataBase_Class::showDataBase()
{
    initDataBase();
    for(auto&vv : jsonDataBase)
    {
        QJsonDocument jsonDoc = QJsonDocument(vv);
        QString jsonStr = QString::fromUtf8(jsonDoc.toJson());
        qDebug().noquote()<<jsonStr<<Qt::endl;
    }
}

void DataBase_Class::initDataBase()
{
    jsonDataBase.clear();
    QFile file(FilePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray byteArr = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);
        QJsonArray JsonArr = jsonDoc.array();
        for(int i=0;i<JsonArr.size();i++)
        {
            QJsonObject jsonObj= JsonArr[i].toObject();
            jsonDataBase<<jsonObj;
        }
        file.close();
    }
    else
    {
        qDebug()<<"Can't Open the database file"<<Qt::endl;
    }
}
