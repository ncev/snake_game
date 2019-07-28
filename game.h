#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL2/SDL.h>
#include <sys/time.h>
#include "welcomepage.h"
#include "apple.h"
#include "snake.h"

using namespace std;

class Game
{
private:
    Apple* apple;
    Snake* snake;
    WelcomePage* welcomePage;
    SDL_Renderer* renderer;
    Coord* max;
    pthread_t tid;
    int state_game;
    string keyboardTouch;
public:
    Game(SDL_Renderer* renderer);
    ~Game();
    void mainLoop(SDL_Event event);
    void drawApple();
    void drawSquare(Coord coord, Uint8 r, Uint8 g, Uint8 b);
    void draw();
    void start();
    void run_game(long sec);
};

#endif // GAME_H
