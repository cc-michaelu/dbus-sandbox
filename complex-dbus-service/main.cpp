#include "complexinterface.h"
#include <QCoreApplication>
#include <QDBusConnection>
#include <QDebug>
#include <initializer_list>
#include <signal.h>
#include <unistd.h>

#define BENCH_SERVICE "com.cana.complex"

/**
 * @brief main Start the D-Bus service
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[]) {
    // Attempt to register service, if already running exit with result code 10
    if (QDBusConnection::sessionBus().registerService(BENCH_SERVICE)) {
        QCoreApplication a(argc, argv);
        complexInterface benchIf(&a);

        return a.exec();
    } else {
        qWarning() << "Service is already running";
        return 10;
    }
}
