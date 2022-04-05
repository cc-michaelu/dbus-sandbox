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

    QStringList getStringList();
    customData getCustomData();
    QList<customData> getCustomDataList();

  signals:

  private slots:
    void onTimer();

  private:
    QTimer timer;
    QString the_string = "This is a test";
};

#endif // __COMPLEXINTERFACE_H__