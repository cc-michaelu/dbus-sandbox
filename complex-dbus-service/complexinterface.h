#ifndef __COMPLEXINTERFACE_H__
#define __COMPLEXINTERFACE_H__

#include "customdata.h"
#include <QObject>
#include <QTimer>
#include <memory>

class complexInterface : public QObject {
    Q_OBJECT;
    Q_CLASSINFO("D-Bus Interface", "com.cana.complex")

  public:
    complexInterface(QObject *parent = nullptr);
    virtual ~complexInterface();

  public slots:
    void quit();

    QString getString();
    void setString(QString str);

    void setStringList(QStringList list);

    QStringList getStringList();
    customData getCustomData();
    QList<customData> getCustomDataList();

    QVariantList getListOfMaps();

  signals:

  private slots:
    void onTimer();

  private:
    QTimer timer;
    QString the_string = "This is a test";
    QStringList the_string_list = {
      "Item #1",
      "Item #2",
      "Item #3",
    };
};

#endif // __COMPLEXINTERFACE_H__