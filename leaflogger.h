#ifndef LEAFLOGGER_H
#define LEAFLOGGER_H

#include <QObject>
#include <QWidget>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
class LeafLogger : public QObject
{
    Q_OBJECT
public:
    explicit LeafLogger(QObject *parent = nullptr);

    void LogMessage(const QString log, const char *func, const char *file, int line) const;
    void LogMessage(const QString log, const char *func) const;
    void LogMessage(const QString log) const;
    void LogMessage(const wchar_t* log);
    static void setFilePath(QString Path);
    LeafLogger& operator<<(const QString log);
    LeafLogger& operator<<(const wchar_t* log);
signals:

public slots:
private:
    static QFile* file;
    static bool isFileSetPath;

};
#endif // LEAFLOGGER_H
