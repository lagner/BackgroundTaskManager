#-------------------------------------------------
#
# Project created by QtCreator 2016-03-06T12:38:32
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET = tst_wordcountertests
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

#DEFINES += SRCDIR=\\\"$$PWD/\\\"

PROJ_SRC = $$PWD"/../app/src"

INCLUDEPATH += $$PROJ_SRC

SOURCES += tst_wordcountertests.cpp \
    $$PROJ_SRC/wordcounter.cpp

HEADERS += \
    $$PROJ_SRC/wordcounter.h


