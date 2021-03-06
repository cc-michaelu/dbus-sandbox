#include "customdata.h"
#include <QDebug>
#include <QtDBus>

customData::customData() : name("undefined"), value(-10) {
    // qDebug() << Q_FUNC_INFO;
}
customData::customData(const QString &name, int value)
    : name(name), value(value) {
    // qDebug() << Q_FUNC_INFO;
}
customData::customData(const customData &other)
    : name(other.name), value(other.value) {
    // qDebug() << Q_FUNC_INFO;
}
// customData::customData(customData &&other)
//     : name(std::move(other.name)), value(other.value) {}
// customData::~customData() {}

customData::~customData() {
    // qDebug() << Q_FUNC_INFO;
}

customData &customData::operator=(const customData &other) {

    name = other.name;
    value = other.value;

    return *this;
}

QString customData::getName() const { return name; }

int customData::getValue() const { return value; }

void customData::registerMetaType() {
    qRegisterMetaType<customData>("customData");
    qRegisterMetaType<QList<customData>>("QList<customData>");
    qRegisterMetaType<QList<QVariantMap>>("QList<QVariantMap>");

    qDBusRegisterMetaType<customData>();
    qDBusRegisterMetaType<QList<customData>>();
    qDBusRegisterMetaType<QList<QVariantMap>>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const customData &data) {
    argument.beginStructure();
    argument << data.name;
    argument << data.value;
    argument.endStructure();

    return argument;
}
const QDBusArgument &operator>>(const QDBusArgument &argument,
                                customData &data) {
    argument.beginStructure();
    argument >> data.name;
    argument >> data.value;
    argument.endStructure();

    return argument;
}
