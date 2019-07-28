#include "welcomepage.h"
#include "game.h"

WelcomePage::WelcomePage(SDL_Renderer* renderer, Game* game)
{
    this->renderer = renderer;
    this->game = game;
}

void WelcomePage::showWelcomePage() {
    SDL_SetRenderDrawColor(renderer, 52, 72, 94, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    game->start();
}
