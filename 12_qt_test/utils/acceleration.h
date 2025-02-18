#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>
#include "utils_global.h"

class Acceleration : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double value READ get NOTIFY changed)
public:
    explicit Acceleration(QObject *parent = nullptr);

    double get();

signals:
    void changed(double v);

public slots:
    void onChange(double v);

private:
    double first{};
    double second{};
};

#endif // ACCELERATION_H
