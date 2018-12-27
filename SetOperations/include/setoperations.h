#ifndef SETOPERATIONS_H
#define SETOPERATIONS_H

#include "setoperations_global.h"

class SETOPERATIONSSHARED_EXPORT SetOperations
{

public:
    template <typename T>
    static QList<T> getIntersection(QList<QList<T> > lists);
    template <typename T>
    static QList<T> getUnion(QList<QList<T> > lists);
};

#endif // SETOPERATIONS_H
