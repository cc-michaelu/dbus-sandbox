#include "complexProxy.h"
#include "customdata.h"
#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    customData::registerMetaType();

    auto complex_if =
        new ComCanaComplexInterface("com.cana.complex", "/com/cana/complex",
                                    QDBusConnection::sessionBus(), &a);

    auto result = complex_if->getCustomData().value();
    qInfo() << "Name =" << result.getName();
    qInfo() << "Value =" << result.getValue();

    complex_if->deleteLater();

    QTimer::singleShot(0, [&]() { a.quit(); });

    return a.exec();
}
