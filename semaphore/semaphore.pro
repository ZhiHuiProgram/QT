QT += core
QT -= gui

CONFIG += c++11

TARGET = semaphore
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    elder_brother.cpp \
    youngerbrother.cpp

HEADERS += \
    elder_brother.h \
    youngerbrother.h
