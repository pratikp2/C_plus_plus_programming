QT       += core

QT       -= gui
QT += dbus

TARGET = miss
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
demoifadaptor.cpp

HEADERS += \
demoifadaptor.h
