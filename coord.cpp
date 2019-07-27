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
