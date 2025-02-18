#ifndef SPEED_H
#define SPEED_H

#include <QObject>
#include "utils_global.h"

class Speed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double value READ get NOTIFY changed)

public:
    explicit Speed(QObject *parent = nullptr);

    double get();

signals:
    void changed(double v);

public slots:
    void onChange(double v);

private:
    double first{};
    double second{};
};

#endif // SPEED_H
