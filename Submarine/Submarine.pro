#-------------------------------------------------
#
# Project created by QtCreator 2019-01-23T16:18:37
#
#-------------------------------------------------

QT       += core gui \
                multimedia

CONFIG   -= x86_64
CONFIG   += sdk_no_version_check


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Submarine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    submarine.cpp \
    torpedo.cpp \
    gegner.cpp \
    score.cpp \
    level.cpp \
    spiel.cpp

HEADERS += \
    submarine.h \
    torpedo.h \
    gegner.h \
    score.h \
    level.h \
    spiel.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    dateien.qrc
