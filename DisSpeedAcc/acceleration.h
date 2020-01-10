#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>

class Acceleration : public QObject
{
    Q_PROPERTY( double value READ get
                             WRITE set
                             NOTIFY changed )
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

    Q_INVOKABLE double get();
    Q_INVOKABLE void set( double v);

signals:
    void changed(double v);
public slots:
    void onSpeedChanged(double v);
private:
    bool hasFirstValue;
    bool hasSecondValue;

    double firstValue;
    double secondValue;
};

#endif // ACCELERATION_H
