#include "coord.h"

Coord::Coord()
{
    x = new int(0);
    y = new int(0);
}

Coord::Coord(int x, int y)
{
    this->x = new int(x);
    this->y = new int(y);
}

Coord::~Coord()
{

}


int Coord::getX() {
    return *x;
}

int Coord::getY() {
    return *y;
}

void Coord::setX(int x_) {

    *x = x_;
}

void Coord::setY(int y_) {
    *y = y_;
}

void Coord::copy(Coord* coord) {
    *x = coord->getX();
    *y = coord->getY();
}

Coord* Coord::generateRandomCoord(Coord max) {
    Random* rand = Random::get_instance();

    int X = rand->generateBetween(0, max.getX());
    int Y = rand->generateBetween(0, max.getY());

    return new Coord(X, Y);
}

Coord* Coord::generateRandomCoordNotInCoords(Coord max, vector<Coord*>* coordsNotIn) {
    bool found = false;
    Coord* coord = nullptr;
    while (!found) {
        coord = generateRandomCoord(max);
        found = true;
        for (Coord* c : *coordsNotIn) {
            if (coord->getX() == c->getX() && coord->getY() == c->getY()) {
                found = false;
                break;
            }
        }
    }

    return coord;
}
