#ifndef SPEED_H
#define SPEED_H

#include <QObject>
#include <QDebug>
class Speed : public QObject
{
    Q_PROPERTY( float value READ get
                            //WRITE setValue
                            NOTIFY onDisplacementChanged )
    Q_OBJECT
public:
    explicit Speed(QObject *parent = nullptr);
    double get();
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
