TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += src/__include__

HEADERS += \
    src/animals/animal.h \
    src/animals/dog.h \
    src/animals/cat.h \
    src/__rm_utilities__/__rm_utilities__.h \
    src/animals/animals

SOURCES += src/main.cpp

QMAKE_CXXFLAGS = -std=c++11
