TEMPLATE = app
TARGET = "Ramble's SAS GUI"
RC_ICONS = ".\assets\icons\icon.ico"

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

SOURCES += \
    main.cpp \
    sas.cpp \
    window.cpp

HEADERS += \
    header.h \
    window.h
