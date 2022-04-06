#include "complexinterface.h"
#include "complexAdaptor.h"
#include <QDebug>
#include <QList>
#include <QMetaObject>
#include <QObject>
#include <QVariantMap>

complexInterface::complexInterface(QObject *parent)
    : QObject(parent) /*, timer(this)*/ {
    qDebug() << Q_FUNC_INFO;
    new ComplexAdaptor(this);

    customData::registerMetaType();

    qDebug() << "Registering object...";
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/com/cana/complex", this);
}

complexInterface::~complexInterface() { qDebug() << Q_FUNC_INFO; }

void complexInterface::quit() {
    qDebug() << Q_FUNC_INFO;
    ((QCoreApplication *)parent())->quit();
}

void complexInterface::onTimer() { qDebug() << Q_FUNC_INFO; }

QString complexInterface::getString() {
    qDebug() << Q_FUNC_INFO;
    return the_string;
}

void complexInterface::setString(QString str) { the_string = str; }

QStringList complexInterface::getStringList() { return the_string_list; }

customData complexInterface::getCustomData() {
    customData data("michael", 50);

    return data;
}

QList<customData> complexInterface::getCustomDataList() {
    QList<customData> list = {
        customData("michael", 50),
        customData("dale", 50),
        customData("frank", 50),
        customData("oner", 50),
    };

    return list;
}

void complexInterface::setStringList(QStringList list) {
    qDebug() << Q_FUNC_INFO;
    qInfo() << list;
    the_string_list = list;
}

QVariantList complexInterface::getListOfMaps() {
    qDebug() << Q_FUNC_INFO;

    QVariantList newlist = {
        QVariantMap({
            {"name", "michael"},
            {"age", 40},
        }),
        QVariantMap({
            {"name", "james"},
            {"age", 42},
        }),
    };

    // QVariantMap map;

    // map.clear();
    // map["name"] = "michael";
    // map["age"] = 50;

    // newlist.push_back(map);

    // map.clear();
    // map["name"] = "ritesh";
    // map["age"] = 45;

    // newlist.push_back(map);

    return newlist;
}
