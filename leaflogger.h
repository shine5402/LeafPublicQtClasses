#ifndef LEAFLOGGER_H
#define LEAFLOGGER_H

#include <QObject>
#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QTextCodec>
#include <QSysInfo>
class LeafLogger
{
public:
    explicit LeafLogger();
    static void LogMessage(const QString log, const char *func, const char *file, int line) ;
    static void LogMessage(const QString log, const char *func) ;
    static void LogMessage(const QString log) ;
    static void LogMessage(const wchar_t* log);
    static void setFilePath(QString Path);
    static void setFilePathWithTime();
    LeafLogger& operator<<(const QString log);
    LeafLogger& operator<<(const wchar_t* log);
    static LeafLogger getLogger();
    static void LogSysInfo();
    static void LogInit();
private:
    static bool isFileSetPath;
    static QString filePath;

};
#endif // LEAFLOGGER_H
