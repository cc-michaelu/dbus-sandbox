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

    qInfo() << "Calling getCustomData()";
    auto custom_data_result = complex_if->getCustomData().value();
    qInfo() << "Name =" << custom_data_result.getName();
    qInfo() << "Value =" << custom_data_result.getValue();

    qInfo() << "Calling getCustomDataList()";
    auto result = complex_if->getCustomDataList().value();

    for (const auto &custom : result) {
        qInfo().nospace() << "{ " << custom.getName() << ", "
                          << custom.getValue() << " }";
    }
    // qInfo() << result;

    complex_if->deleteLater();

    QTimer::singleShot(0, [&]() { a.quit(); });

    return a.exec();
}
