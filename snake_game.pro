TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH+= /SDL2-2.0.0/include
LIBS +=-L/SDL2-2.0.0/lib/x64 -lSDL2
LIBS +=-L/SDL2-2.0.0/lib/x64 -lSDL2main
LIBS +=-lpthread

SOURCES += \
        apple.cpp \
        coord.cpp \
        game.cpp \
        main.cpp \
        random.cpp \
        snake.cpp \
        welcomepage.cpp

HEADERS += \
    apple.h \
    coord.h \
    game.h \
    random.h \
    snake.h \
    welcomepage.h
