#include "game.h"

Game::Game(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    apple = nullptr;
    max.x = 25;
    max.y = 19;
    welcomePage();
}

Game::~Game() {
    delete apple;
}

void Game::welcomePage() {
    SDL_SetRenderDrawColor(renderer, 52, 72, 94, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::start() {
    apple = new Apple(max);

    draw();
    SDL_RenderPresent(renderer);
}

void Game::onEvent(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYUP:
            cout << static_cast<char>(event.key.keysym.sym) << endl;
            break;
    }
}

void Game::drawSquare(Coord coord, Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect;
    rect.x = coord.x * 19;
    rect.y = coord.y * 25;
    rect.w = 25;
    rect.h = 25;
    SDL_RenderFillRect(renderer, &rect);
}

void Game::draw() {
    // dessin de font
    SDL_SetRenderDrawColor(renderer, 236, 240, 241, 255);
    SDL_RenderClear(renderer);

    // dessin de la pomme
    Coord coordApple = apple->getCoord();
    drawSquare(coordApple, 46, 204, 113);
}
