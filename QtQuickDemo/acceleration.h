#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QObject>
#include <QDebug>
class Acceleration : public QObject
{ 
    Q_OBJECT
public:
    explicit Acceleration(QObject *parent = nullptr);

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
