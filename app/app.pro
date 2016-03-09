TEMPLATE = app

QT += qml quick
CONFIG += c++11
RESOURCES += qml.qrc

include(deployment.pri)

SOURCES += \
    src/main.cpp \
    src/context.cpp \
    src/wordcounter.cpp \
    src/backgroundtask.cpp \
    src/wordmentionsmodel.cpp

HEADERS += \
    src/context.h \
    src/wordcounter.h \
    src/backgroundtask.h \
    src/wordmentionsmodel.h \
    src/common.h \
    src/utils.h

