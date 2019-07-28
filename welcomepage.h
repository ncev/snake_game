#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H
#include <SDL2/SDL.h>
#include <unistd.h>

class Game;

class WelcomePage
{
private:
    SDL_Renderer* renderer;
    Game* game;
public:
    WelcomePage(SDL_Renderer* renderer, Game* game);
    void showWelcomePage();
};
#endif // WELCOMEPAGE_H
