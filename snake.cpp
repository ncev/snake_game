#include "snake.h"

Snake::Snake(Coord* max)
{
    queue = new vector<Coord*>();
    int X = max->getX() / 2;
    int Y = max->getY() / 2;

    queue->push_back(new Coord(X, Y));
    queue->push_back(new Coord(X - 1, Y));
    queue->push_back(new Coord(X - 2, Y));
}

Snake::~Snake() {
    for (unsigned int i = 0; i != queue->size(); i++) {
        delete queue->at(i);
    }
    delete queue;
}

vector<Coord*>* Snake::getQueue() {
    return queue;
}
