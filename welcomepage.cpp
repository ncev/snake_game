#include "welcomepage.h"
#include "game.h"

WelcomePage::WelcomePage(SDL_Renderer* renderer, Game* game)
{
    this->renderer = renderer;
    this->game = game;
}

void WelcomePage::showWelcomePage() {
    print();
}

void WelcomePage::showWelcomePage(int score) {
    cout << "votre score est de " << score << endl;
    print();
}

void WelcomePage::print() {
    SDL_SetRenderDrawColor(renderer, 52, 72, 94, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void WelcomePage::mainLoop(SDL_Event event) {
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            cout << event.motion.x << endl;
            game->start();
            break;
    }
}
