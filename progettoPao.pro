QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = BiblioTech
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
        gerarchia/item.cpp \
        gerarchia/libro.cpp \
        gerarchia/fumetto.cpp \
        gerarchia/rivista.cpp \
        gerarchia/settimanale.cpp \
        gerarchia/mensile.cpp \
        template/container.cpp \
        template/deepptr.cpp \
        util/carrello.cpp \
        model/model.cpp \
        util/xmlio.cpp \
        view/finestraprincipale.cpp \
        view/finestradimodifica.cpp \
        util/listasmart.cpp \
        view/finestradiinserimento.cpp \
        controller/controller.cpp \
        main.cpp

HEADERS += \
        gerarchia/item.h \
        gerarchia/libro.h \
        gerarchia/fumetto.h \
        gerarchia/rivista.h \
        gerarchia/settimanale.h \
        gerarchia/mensile.h \
        template/container.h \
        template/deepptr.h \
        util/carrello.h \
        model/model.h \
        util/xmlio.h \
        view/finestraprincipale.h \
        view/finestradimodifica.h \
        util/listasmart.h \
        view/finestradiinserimento.h \
        controller/controller.h \
