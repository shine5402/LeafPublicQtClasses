#include "../include/setoperations.h"

template<typename T>
QList<T> SetOperations::getIntersection(QList<QList<T> > lists)
{
    QHash<T,int> counts;
    QList<T> result;
    for (auto list : lists)
    {
        for (auto i : list)
        {
            counts.insert(i,counts.value(i) + 1);
        }
    }
    for (auto it = counts.begin();it != counts.end();++it)
    {
        if (it.value() == lists.count())
            result.append(it.key());
    }
    return result;
}

template<typename T>
QList<T> SetOperations::getUnion(QList<QList<T> > lists)
{
    QList<T> result;
    for (auto list : lists)
    {
        for (auto i : list)
        {
            if (!result.contains(i))
                result.append(i);
        }
    }
    return result;
}

