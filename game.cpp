#include "game.h"
#include <time.h>

Game::Game(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    apple = nullptr;
    snake = nullptr;
    seconds = -1;
    state_game = 0;

    max = new Coord(25, 19);
    start();
}

Game::~Game() {
    delete apple;
    delete snake;
    delete max;
}

void Game::welcomePage() {
    state_game = 0;
    SDL_SetRenderDrawColor(renderer, 52, 72, 94, 255);
    SDL_RenderClear(renderer);
}

void Game::start() {
    state_game = 1;
    snake = new Snake(max);
    apple = new Apple(max, snake->getQueue());
    draw();
}

void Game::mainLoop(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYUP:
            cout << static_cast<char>(event.key.keysym.sym) << endl;
            break;
    }
    time_t t = time(nullptr);
    struct tm tm = *localtime(&t);
    if (seconds != tm.tm_sec) {
        seconds = tm.tm_sec;
        switch (state_game) {
            case 1:
                run_game();
                break;
        }
    }
}

void Game::run_game() { // cette méthode s'execute toutes les 1 secondes
    snake->loopMovement();
    draw();
}

void Game::drawSquare(Coord coord, Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect;
    rect.x = coord.getX() * max->getX();
    rect.y = coord.getY() * max->getY();
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


    // dessin de la queue
    for (Coord* coord : *snake->getQueue()) {
        drawSquare(*coord, 52, 252, 219);
    }
    SDL_RenderPresent(renderer);
}
