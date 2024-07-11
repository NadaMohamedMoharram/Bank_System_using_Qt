#ifndef DATABASE_CLASS_H
#define DATABASE_CLASS_H

#include <QObject>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonDocument>
#include<QFile>
#include<QVector>
#include<QDebug>
class DataBase_Class : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    void addObject(QString name,qint32 age);
    void updateObject(qint32 id,QString name,qint32 age);
    void deleteObject(qint32 id);
    void showDataBase();
private:
    QString FilePath;
    QVector<QJsonObject> jsonDataBase;
    void initDataBase();
};

#endif // DATABASE_CLASS_H
