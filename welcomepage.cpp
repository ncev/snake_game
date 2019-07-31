#include "welcomepage.h"
#include "game.h"

WelcomePage::WelcomePage(SDL_Renderer* renderer, Game* game)
{
    this->renderer = renderer;
    this->game = game;
    police = TTF_OpenFont("angelina.ttf", 65);
    couleurNoire = {0, 0, 0, 0};

    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    welcomeRect.x = w / 2 - 200;  //controls the rect's x coordinate
    welcomeRect.y = 0; // controls the rect's y coordinte
    welcomeRect.w = 400; // controls the width of the rect
    welcomeRect.h = 100; // controls the height of the rect

    scoreRect.x = w / 2 - 200;  //controls the rect's x coordinate
    scoreRect.y = h / 2 - 50; // controls the rect's y coordinte
    scoreRect.w = 400; // controls the width of the rect
    scoreRect.h = 100; // controls the height of the rect


    if(!police) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        // handle error
    }

}

WelcomePage::~WelcomePage() {
    TTF_CloseFont(police);
}

void WelcomePage::showWelcomePage() {
    print(nullptr);
}

void WelcomePage::showWelcomePage(int score) {
    string str_score = "votre score est de " + to_string(score);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(police, str_score.c_str(), couleurNoire);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    print(scoreTexture);
}

void WelcomePage::print(SDL_Texture* scoreTexture) {
    SDL_SetRenderDrawColor(renderer, 52, 72, 94, 255);
    SDL_RenderClear(renderer);

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(police, "Cliquez pour jouer !", couleurNoire);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_RenderCopy(renderer, Message, nullptr, &welcomeRect);

    if (scoreTexture != nullptr) {
        SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
    }

    SDL_RenderPresent(renderer);

    SDL_FreeSurface(surfaceMessage);
    free(Message);
}

void WelcomePage::mainLoop(SDL_Event event) {
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            game->start();
            break;
    }
}
