#ifndef DEMO_H
#define DEMO_H

#include <QObject>
#include "utils_global.h"

class demo : public QObject
{
    Q_OBJECT
public:
    explicit demo(QObject *parent = nullptr);
    int sum(int a, int b);

signals:

public slots:
};

#endif // DEMO_H
