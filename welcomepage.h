#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <unistd.h>

class Game;

class WelcomePage
{
private:
    SDL_Renderer* renderer;
    Game* game;
    TTF_Font *police;
    SDL_Color couleurNoire;
    SDL_Rect welcomeRect;
    SDL_Rect scoreRect;

    void print(SDL_Texture* scoreTexture);
public:
    WelcomePage(SDL_Renderer* renderer, Game* game);
    ~WelcomePage();
    void showWelcomePage();
    void showWelcomePage(int score);
    void mainLoop(SDL_Event event);
};
#endif // WELCOMEPAGE_H
