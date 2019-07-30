#include "snake.h"
#include <unistd.h>
#include <algorithm>    // std::rotate

Snake::Snake(Coord* max)
{
    end = false;
    queue = new vector<Coord*>();
    this->max = max;
    int X = max->getX() / 2;
    int Y = max->getY() / 2;

    queue->push_back(new Coord(X, Y));
    queue->push_back(new Coord(X - 1, Y));

    queueMov.insert(std::pair<string,void (*) (Coord*)>("Right", Snake::queueRight));
    queueMov.insert(std::pair<string,void (*) (Coord*)>("Left", Snake::queueLeft));
    queueMov.insert(std::pair<string,void (*) (Coord*)>("Up", Snake::queueUp));
    queueMov.insert(std::pair<string,void (*) (Coord*)>("Down", Snake::queueDown));
    queueChange = "";
}

Snake::~Snake() {
    for (unsigned int i = 0; i != queue->size(); i++) {
        delete queue->at(i);
    }
    delete queue;
}

void Snake::loopMovement(string queueChange, long) {
    if (queueChange != this->queueChange && queueMov.find(queueChange) != queueMov.end()) {
        this->queueChange = queueChange;
    }
    if (queueChange != "") {
        updateQueuePos();
        end = checkQueuePos();
    }
}

bool Snake::checkQueuePos() {
    int X = queue->at(0)->getX();
    int Y = queue->at(0)->getY();

    return ((X >= max->getX() || Y >= 475 / max->getY()) || (X <= 0 || Y <= 0));
}

void Snake::updateQueuePos() {
    queue->erase(queue->begin() + 1);
    queue->push_back(new Coord(queue->at(0)->getX(), queue->at(0)->getY()));
    queueMov.at(queueChange)(queue->at(0));
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

void Snake::queueRight(Coord* coord) {
    coord->setX(coord->getX() + 1);
}

void Snake::queueLeft(Coord* coord) {
    coord->setX(coord->getX() - 1);
}

void Snake::queueUp(Coord* coord) {
    coord->setY(coord->getY() - 1);
}

void Snake::queueDown(Coord* coord) {
    coord->setY(coord->getY() + 1);
}
