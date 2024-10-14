#ifndef LOGGING_H
#define LOGGING_H

#include <QString>
#include <QTimer>
#include <QFile>
#include <QJsonObject>
#include <QDateTime>
#include <QObject>

class Logging : public QObject {
    Q_OBJECT
public:
    Logging();
    void startLogging();
    void loadConfig(const QString& configPath);

private:
    QString logType;
    QString logFrequency;
    int logSize;
    QString logDirectory;

    void createLog();
    void manageLogFiles();
    QString getCurrentUTCTime();
};

#endif
