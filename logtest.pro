TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Class1.cpp \
    Log.cpp


INCLUDEPATH += /usr/local/include/log4cplus

LIBS += `pkg-config --libs log4cplus`

HEADERS += \
    Class1.h \
    Log.h

DESTDIR = $$system(pwd)/build
OBJECTS_DIR = $$DESTDIR
