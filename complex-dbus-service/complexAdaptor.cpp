/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a complexAdaptor com.cana.complex.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "complexAdaptor.h"
#include "customdata.h"
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QMetaObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class ComplexAdaptor
 */

ComplexAdaptor::ComplexAdaptor(QObject *parent) : QDBusAbstractAdaptor(parent) {
    // constructor
    setAutoRelaySignals(true);
}

ComplexAdaptor::~ComplexAdaptor() {
    // destructor
}

customData ComplexAdaptor::getCustomData() {
    // handle method call com.cana.complex.getCustomData
    customData out0;
    QMetaObject::invokeMethod(parent(), "getCustomData",
                              Q_RETURN_ARG(customData, out0));
    return out0;
}

QList<customData> ComplexAdaptor::getCustomDataList() {
    // handle method call com.cana.complex.getCustomDataList
    QList<customData> out0;
    QMetaObject::invokeMethod(parent(), "getCustomDataList",
                              Q_RETURN_ARG(QList<customData>, out0));
    return out0;
}

QVariantList ComplexAdaptor::getListOfMaps()
{
    // handle method call com.cana.complex.getListOfMaps
    QVariantList out0;
    QMetaObject::invokeMethod(parent(), "getListOfMaps", Q_RETURN_ARG(QVariantList, out0));
    return out0;
}

QString ComplexAdaptor::getString() {
    // handle method call com.cana.complex.getString
    QString out0;
    QMetaObject::invokeMethod(parent(), "getString",
                              Q_RETURN_ARG(QString, out0));
    return out0;
}

QStringList ComplexAdaptor::getStringList() {
    // handle method call com.cana.complex.getStringList
    QStringList out0;
    QMetaObject::invokeMethod(parent(), "getStringList",
                              Q_RETURN_ARG(QStringList, out0));
    return out0;
}

void ComplexAdaptor::quit() {
    // handle method call com.cana.complex.quit
    QMetaObject::invokeMethod(parent(), "quit");
}

void ComplexAdaptor::setString(const QString &str) {
    // handle method call com.cana.complex.setString
    QMetaObject::invokeMethod(parent(), "setString", Q_ARG(QString, str));
}

void ComplexAdaptor::setStringList(const QStringList &list) {
    // handle method call com.cana.complex.setStringList
    QMetaObject::invokeMethod(parent(), "setStringList",
                              Q_ARG(QStringList, list));
}

