#include "logging.h"
#include <QCoreApplication>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Logging::Logging() : logDirectory(QCoreApplication::applicationDirPath() + "/logs/") {
}

void Logging::loadConfig(const QString& configPath) {
    QFile configFile(configPath);
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Config dosyası açılamadı: " << configPath;
        return;
    }

    // config.json okuma
    QByteArray configData = configFile.readAll();
    QJsonDocument configDoc = QJsonDocument::fromJson(configData);
    QJsonObject configObject = configDoc.object();

    logType = configObject["logType"].toString();
    logFrequency = configObject["logFrequency"].toString();
    logSize = configObject["logSize"].toInt();

    configFile.close();
}

void Logging::createLog() {
    QDir dir(logDirectory);
    if (!dir.exists()) {
        dir.mkpath(logDirectory);
    }

    // Log adı ve yolu
    QString logFileName = logDirectory + getCurrentUTCTime() + "." + logType;
    QFile logFile(logFileName);

    qDebug() << "Log dosyası oluşturulmaya çalışılıyor: " << logFileName;

    // Log oluşturma
    if (logFile.open(QIODevice::WriteOnly)) {
        QTextStream stream(&logFile);
        stream << "Log created at " << getCurrentUTCTime() << "\n";
        logFile.close();
        qDebug() << "Log dosyası başarıyla oluşturuldu.";
    } else {
        qWarning() << "Log dosyası oluşturulamadı: " << logFileName;
        qWarning() << "Hata: " << logFile.errorString();
    }

    manageLogFiles();
}

QString Logging::getCurrentUTCTime() {
    return QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddThh_mm_ss");
}

void Logging::manageLogFiles() {
    QDir dir(logDirectory);
    QStringList logFiles = dir.entryList(QStringList() << "*." + logType, QDir::Files, QDir::Time);

    // logSize (maksimum dosya) kontrolu
    while (logFiles.size() > logSize) {
        QString oldestLogFile = logFiles.takeLast();
        dir.remove(oldestLogFile);
        qDebug() << "Silinen log dosyası: " << oldestLogFile;
    }
}

void Logging::startLogging() {
    QTimer *timer = new QTimer(this);

    if (logFrequency == "second") {
        timer->setInterval(1000);
    } else if (logFrequency == "minute") {
        timer->setInterval(60000);
    } else if (logFrequency == "hour") {
        timer->setInterval(3600000);
    } else if (logFrequency == "day") {
        timer->setInterval(86400000);
    }

    connect(timer, &QTimer::timeout, this, &Logging::createLog);
    timer->start();
}
