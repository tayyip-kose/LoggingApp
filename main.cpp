#include <QCoreApplication>
#include "logging.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Logging logging;

    // Config
    logging.loadConfig(QCoreApplication::applicationDirPath() + "/config.json");
    logging.startLogging();

    return a.exec();
}
