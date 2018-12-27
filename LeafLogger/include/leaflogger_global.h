#ifndef LEAFLOGGER_GLOBAL_H
#define LEAFLOGGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LEAFLOGGER_LIBRARY)
#  define LEAFLOGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LEAFLOGGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LEAFLOGGER_GLOBAL_H
