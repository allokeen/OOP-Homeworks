#ifndef DEMO_H
#define DEMO_H

#include <QObject>
#include <QDebug>

class Demo : public QObject
{
    Q_OBJECT

    Q_PROPERTY( float value READ getValue
                            WRITE setValue
                            NOTIFY valueChanged )
public:
    explicit Demo(QObject *parent = nullptr);

    Q_INVOKABLE void doSomething();

    void setValue(float v);
    float getValue() const;
signals:

    void test();
    void valueChanged();

public slots:

private:
    float value;
};

#endif // DEMO_H
