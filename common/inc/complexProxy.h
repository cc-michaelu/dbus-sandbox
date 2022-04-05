/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -N -p complexProxy com.cana.complex.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef COMPLEXPROXY_H
#define COMPLEXPROXY_H

#include "customdata.h"
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.cana.complex
 */
class ComCanaComplexInterface : public QDBusAbstractInterface {
    Q_OBJECT
  public:
    static inline const char *staticInterfaceName() {
        return "com.cana.complex";
    }

  public:
    ComCanaComplexInterface(const QString &service, const QString &path,
                            const QDBusConnection &connection,
                            QObject *parent = nullptr);

    ~ComCanaComplexInterface();

  public Q_SLOTS: // METHODS
    inline QDBusPendingReply<customData> getCustomData() {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("getCustomData"),
                                         argumentList);
    }

    inline QDBusPendingReply<QList<customData>> getCustomDataList() {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("getCustomDataList"),
                                         argumentList);
    }

    inline QDBusPendingReply<QString> getString() {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("getString"),
                                         argumentList);
    }

    inline QDBusPendingReply<QStringList> getStringList() {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("getStringList"),
                                         argumentList);
    }

    inline QDBusPendingReply<> quit() {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("quit"), argumentList);
    }

    inline QDBusPendingReply<> setString(const QString &str) {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(str);
        return asyncCallWithArgumentList(QStringLiteral("setString"),
                                         argumentList);
    }

  Q_SIGNALS: // SIGNALS
};

#endif
