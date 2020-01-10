#ifndef SPEED_H
#define SPEED_H

#include <QObject>

class Speed : public QObject
{
    Q_PROPERTY( double value READ get
                             WRITE set
                             NOTIFY changed )
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);

    Q_INVOKABLE double get();
    Q_INVOKABLE void set(double v);

signals:
    void changed(double v);
public slots:
    void onDisplacementChanged(double v);
private:
    bool hasFirstValue;
    bool hasSecondValue;

    double firstValue;
    double secondValue;
};

#endif // SPEED_H
