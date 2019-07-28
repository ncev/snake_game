#include "snake.h"

Snake::Snake(Coord* max)
{
    end = false;
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

void Snake::loopMovement() {
    cout << "loop snake movement"<< endl;
}

vector<Coord*>* Snake::getQueue() {
    return queue;
}

bool Snake::isEnded() {
    return end;
}

void Snake::setEnded(bool end) {
    this->end = end;
}
