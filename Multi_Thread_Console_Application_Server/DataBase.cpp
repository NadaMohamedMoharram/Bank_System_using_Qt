#include "DataBase.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent},FilePath{"D:\\ITIDA_Scholarship\\Final project\\Bank_System\\Multi_Thread_Console_Application_Server\\Database\\LoginDB.json"}
{
    initDataBase();
}

void DataBase::addObject(QString name, qint32 age)
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

void DataBase::updateObject(qint32 id, QString name, qint32 age)
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

void DataBase::deleteObject(qint32 id)
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

void DataBase::showDataBase()
{
    initDataBase();
    for(auto&vv : jsonDataBase)
    {
        QJsonDocument jsonDoc = QJsonDocument(vv);
        QString jsonStr = QString::fromUtf8(jsonDoc.toJson());
        qDebug().noquote()<<jsonStr<<Qt::endl;
    }
}

void DataBase::initDataBase()
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




QString DataBase::verifyCredentials(const QString& username, const QString& password)
{
    initDataBase();
    for (const auto& user : jsonDataBase)
    {
        if (user["Username"].toString() == username && user["Password"].toString() == password)
        {
            return user["Autority"].toString();
        }
    }
    return QString();  // Return an empty string if the user is not found
}


QString DataBase::getAccountNumber(const QString& username)
{
    initDataBase();
    for (const auto& user : jsonDataBase)
    {
        if (user["Username"].toString() == username)
        {
            return user["AccountNumber"].toString();
        }
    }
    return QString(); // Return an empty string if the user is not found
}

// QString DataBase::GetUserAuthority(const QString &username)
// {
//     initDataBase();
//     for (const auto& user : jsonDataBase)
//     {
//         if (user["Username"].toString() == username )
//         {
//             return user["Autority"].toString();
//         }
//     }
//     return QString();  // Return an empty string if the user is not found
// }
/****************************/


// #include "DataBase.h"


// DataBase::DataBase(QObject *parent)
//     : QObject{parent},
//    FilePath{"D:\\ITIDA_Scholarship\\Task_Qt\\JSON\\untitled\\DataBaseFile.json"}
// {
//     initDataBase();
// }

// void DataBase::addObject(QString category, QString name, QString password)
// {
//     initDataBase();

//     if (!jsonDataBase.contains(category) || !jsonDataBase[category].isArray()) {
//         qDebug() << "Invalid category or not an array.";
//         return;
//     }

//     QJsonArray categoryArray = jsonDataBase[category].toArray();
//     QJsonObject newObj;
//     newObj[name] = QJsonObject{{"password", password}};
//     categoryArray.append(newObj);

//     jsonDataBase[category] = categoryArray;

//     writeDataBase();
// }

// void DataBase::updateObject(QString category, QString name, QString password)
// {
//     initDataBase();

//     if (!jsonDataBase.contains(category) || !jsonDataBase[category].isArray()) {
//         qDebug() << "Invalid category or not an array.";
//         return;
//     }

//     QJsonArray categoryArray = jsonDataBase[category].toArray();
//     bool found = false;
//     for (auto &value : categoryArray) {
//         QJsonObject obj = value.toObject();
//         if (obj.contains(name)) {
//             obj[name]["password"] = password;
//             value = obj;
//             found = true;
//             break;
//         }
//     }

//     if (found) {
//         jsonDataBase[category] = categoryArray;
//         writeDataBase();
//     } else {
//         qDebug() << "Object not found.";
//     }
// }

// void DataBase::deleteObject(QString category, QString name)
// {
//     initDataBase();

//     if (!jsonDataBase.contains(category) || !jsonDataBase[category].isArray()) {
//         qDebug() << "Invalid category or not an array.";
//         return;
//     }

//     QJsonArray categoryArray = jsonDataBase[category].toArray();
//     QJsonArray newArray;
//     for (auto &value : categoryArray) {
//         QJsonObject obj = value.toObject();
//         if (!obj.contains(name)) {
//             newArray.append(value);
//         }
//     }

//     jsonDataBase[category] = newArray;
//     writeDataBase();
// }

// void DataBase::showDataBase()
// {
//     initDataBase();
//     qDebug().noquote() << QJsonDocument(jsonDataBase).toJson() << Qt::endl;
// }

// void DataBase::initDataBase()
// {
//     jsonDataBase = QJsonObject();
//     QFile file(FilePath);
//     if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         QByteArray byteArr = file.readAll();
//         QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);
//         jsonDataBase = jsonDoc.object();
//         file.close();
//     } else {
//         qDebug() << "Can't Open the database file" << Qt::endl;
//     }
// }

// void DataBase::writeDataBase()
// {
//     QFile file(FilePath);
//     if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
//         file.write(QJsonDocument(jsonDataBase).toJson());
//         file.close();
//     } else {
//         qDebug() << "Can't Open the database file" << Qt::endl;
//     }
// }
