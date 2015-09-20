#-------------------------------------------------
#
# Project created by QtCreator 2015-09-20T12:39:44
#
#-------------------------------------------------

QT       -= core gui

TARGET = poly2tri
TEMPLATE = lib

DESTDIR = $$PWD/lib

DEFINES += POLY2TRI_LIBRARY

SOURCES += \
    common/shapes.cc \
    sweep/advancing_front.cc \
    sweep/cdt.cc \
    sweep/sweep.cc \
    sweep/sweep_context.cc

HEADERS += poly2tri.h \
    common/shapes.h \
    common/utils.h \
    sweep/advancing_front.h \
    sweep/cdt.h \
    sweep/sweep.h \
    sweep/sweep_context.h \
    common/config.h \
    common/random_utils.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
