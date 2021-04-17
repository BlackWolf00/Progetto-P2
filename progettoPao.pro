#-------------------------------------------------
#
# Project created by QtCreator 2021-03-24T16:45:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

TARGET = Test
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        gerarchia/item.cpp \
        gerarchia/libro.cpp \
        gerarchia/rivista.cpp \
        template/container.cpp \
        template/deepptr.cpp \
    gerarchia/fumetto.cpp \
    util/carrello.cpp \
    model/model.cpp \
    gerarchia/settimanale.cpp \
    gerarchia/mensile.cpp \
    controller/controller.cpp \
    view/finestraprincipale.cpp \
    util/listasmart.cpp

HEADERS += \
        mainwindow.h \
        gerarchia/item.h \
        gerarchia/libro.h \
        gerarchia/rivista.h \
        template/container.h \
        template/deepptr.h \
    gerarchia/fumetto.h \
    util/carrello.h \
    model/model.h \
    gerarchia/settimanale.h \
    gerarchia/mensile.h \
    controller/controller.h \
    view/finestraprincipale.h \
    util/listasmart.h