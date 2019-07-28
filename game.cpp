#include "game.h"

Game::Game(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    welcomePage = new WelcomePage(renderer, this);
    apple = nullptr;
    snake = nullptr;
    seconds = -1;
    state_game = 0;

    max = new Coord(25, 19);
    welcomePage->showWelcomePage();
}

Game::~Game() {
    delete apple;
    delete snake;
    delete max;
}

void Game::start() {
    state_game = 1;
    snake = new Snake(max);
    apple = new Apple(max, snake->getQueue());
    draw();
}

void Game::mainLoop(SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            keyboardTouch = SDL_GetScancodeName(event.key.keysym.scancode);
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
    snake->loopMovement(keyboardTouch);
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
