TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH+= /SDL2-2.0.0/include
LIBS +=-L/SDL2-2.0.0/lib/x64 -lSDL2
LIBS +=-L/SDL2-2.0.0/lib/x64 -lSDL2main

SOURCES += \
        main.cpp
