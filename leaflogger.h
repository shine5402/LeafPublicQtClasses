#ifndef LEAFLOGGER_H
#define LEAFLOGGER_H

#include <QObject>
#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QMutexLocker>
#include <QDir>
#include <QTextCodec>
#include <QSysInfo>
class LeafLogger
{
public:
    static void LogMessage(const QString log, const char *func, const char *file, int line) ;
    static void LogMessage(const QString log, const char *func) ;
    static void LogMessage(const QString log);
    static void LogMessage(const wchar_t* log);
    static void setFilePath(QString Path);
    static void setFilePathWithTime();
    LeafLogger& operator<<(const QString log);
    LeafLogger& operator<<(const wchar_t* log);
    static LeafLogger getLogger();
    static void LogSysInfo();
    static void LogInit();
signals:

public slots:
private:
    static QFile file;
    static bool isFileSetPath;
    static QMutex mutex;
};
#endif // LEAFLOGGER_H
