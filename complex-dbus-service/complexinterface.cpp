#include "complexinterface.h"
#include "complexAdaptor.h"
#include <QDebug>
#include <QList>
#include <QMetaObject>
#include <QObject>

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

QStringList complexInterface::getStringList() {
    QStringList list = {
        "Item #1",
        "Item #2",
        "Item #3",
    };

    return list;
}

customData complexInterface::getCustomData() {
    customData data("michael", 50);

    return data;
}
