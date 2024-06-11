QT += core
QT -= gui

CONFIG += c++11

TARGET = hello_world
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    hello.cpp \
    world.cpp

HEADERS += \
    hello.h \
    world.h
