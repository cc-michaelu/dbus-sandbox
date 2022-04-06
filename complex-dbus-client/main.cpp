#include "complexProxy.h"
#include "customdata.h"
#include <QTextStream>
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

    qInfo() << "Calling getStringList()";
    const auto old_list = complex_if->getStringList().value();
    QString line;
    QTextStream str(&line);
    str << "{ ";
    for (const auto &val : old_list) {

        str << val;
        if (val != old_list.last())
            str << ", ";
    }
    str << " }";

    qInfo().noquote() << line;

    QStringList new_list = {
        "Peter",
        "Paul",
        "Mary",
        "Bob"
    };

    qInfo() << "Calling setStringList()";
    complex_if->setStringList(new_list);

    qInfo() << "Calling getListOfMaps()";
    auto list_of_maps = complex_if->getListOfMaps().value();
    for (const auto &map : list_of_maps) {
        const auto &mymap = qdbus_cast<QVariantMap>(qvariant_cast<QDBusArgument>(map));

        for (const auto & map_key : mymap.keys()) {
            QString line;
            QTextStream os(&line);
            os << qSetFieldWidth(8) << right << map_key << reset << " : " << mymap[map_key].toString();
            qInfo().noquote() << line;
            // qInfo().noquote() << map_keys << ":" << mymap[map_keys].toString();
        }
    }

    QTimer::singleShot(0, [&]() { a.quit(); });

    return a.exec();
}
