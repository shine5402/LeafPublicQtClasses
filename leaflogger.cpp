#include "leaflogger.h"
LeafLogger::LeafLogger(QObject *parent) : QObject(parent)
{

}

void LeafLogger::LogMessage(const QString log) const
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    if (!isFileSetPath) {
        QString log_text = QString(u8"[%1] %2\n").arg(current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz")).arg(QStringLiteral("警告：日志文件IO设备没有被指定路径，日志将不会被记录到文件中。"));
        qDebug() << log_text;
    }

    QString log_text = QString(u8"[%1] %2\n").arg(current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz")).arg(log);
    qDebug() << log_text;
    if (isFileSetPath){
        QTextStream writer(file);
        writer << log_text;
    }
}

void LeafLogger::LogMessage(const wchar_t *log)
{
    LogMessage(QString::fromWCharArray(log));
}

void LeafLogger::setFilePath(QString Path)
{
    if (file->isOpen())
        file->close();
    file->setFileName(Path);
    file->open(QIODevice::ReadWrite);
    //writer.setDevice(file);
    isFileSetPath = true;
}

LeafLogger &LeafLogger::operator<<(const QString log)
{
    LogMessage(log);
    return *this;
}

LeafLogger &LeafLogger::operator<<(const wchar_t *log)
{
    LogMessage(QString::fromWCharArray(log));
    return *this;
}

void LeafLogger::LogMessage(const QString log, const char* func) const
{
    QString log_with_func = QString(u8"函数：%1：%2").arg(func).arg(log);
    LogMessage(log_with_func);
}

void LeafLogger::LogMessage(const QString log, const char* func, const char* file, int line) const
{
    QString log_with_func_line = QString("（%4:%2）函数：%1：%3").arg(func).arg(line).arg(log).arg(file);
    LogMessage(log_with_func_line);
}
QFile* LeafLogger::file = new QFile;
bool LeafLogger::isFileSetPath = false;
//QTextStream LeafLogger::writer = QTextStream(file);


