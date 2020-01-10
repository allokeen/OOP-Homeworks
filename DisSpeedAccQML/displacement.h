#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include <QObject>

class Displacement : public QObject
{
    Q_PROPERTY( double value READ get
                             WRITE set
                             NOTIFY changed )
    Q_OBJECT
public:
    explicit Displacement(QObject *parent = nullptr);

    double get();
    Q_INVOKABLE void set(double v);

signals:
    void changed(double v);
public slots:
private:
    double value;
};

#endif // DISPLACEMENT_H
