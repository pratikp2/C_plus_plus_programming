#-------------------------------------------------
#
# Project created by QtCreator 2016-06-15T12:08:50
#
#-------------------------------------------------

QT       += core gui
QT       += dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp \
    demoif.cpp

HEADERS  += \
    demoif.h

OTHER_FILES += \
    com.nokia.Demo.xml
