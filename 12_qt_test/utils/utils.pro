#-------------------------------------------------
#
# Project created by QtCreator 2020-01-18T23:01:18
#
#-------------------------------------------------

QT       -= gui

TARGET = utils
TEMPLATE = lib

DEFINES += UTILS_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        utils.cpp \
    demo.cpp \
    speed.cpp \
    acceleration.cpp \
    displacement.cpp

HEADERS += \
        utils.h \
        utils_global.h \ 
    demo.h \
    speed.h \
    acceleration.h \
    displacement.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
