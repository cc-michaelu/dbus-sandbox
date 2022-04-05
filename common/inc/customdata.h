#ifndef __CUSTOMDATA_H__
#define __CUSTOMDATA_H__

#include <QDBusArgument>
#include <QList>
#include <QString>

class customData {
  public:
    customData();
    customData(const QString &name, int value);
    customData(const customData &other);
    // customData(customData &&other);
    ~customData();

    customData &operator=(const customData &other);
    friend QDBusArgument &operator<<(QDBusArgument &argument,
                                     const customData &data);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument,
                                           customData &data);

    static void registerMetaType();

    QString getName() const;
    int getValue() const;

  private:
    QString name;
    int value;
};

Q_DECLARE_METATYPE(customData)
Q_DECLARE_METATYPE(QList<customData>)

#endif // __CUSTOMDATA_H__
