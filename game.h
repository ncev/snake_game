#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL2/SDL.h>
#include "apple.h"
#include "snake.h"

using namespace std;

class Game
{
private:
    Apple* apple;
    Snake* snake;
    SDL_Renderer* renderer;
    Coord* max;
public:
    Game(SDL_Renderer* renderer);
    ~Game();
    void onEvent(SDL_Event event);
    void drawApple();
    void drawSquare(Coord coord, Uint8 r, Uint8 g, Uint8 b);
    void draw();
    void start();
    void welcomePage();
};

#endif // GAME_H
