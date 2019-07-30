#include "apple.h"

Apple::Apple(Coord* max, vector<Coord*>* queue)
{
    tmpMax = new Coord(max->getX() - 1, max->getY() - 1);
    Coord* coord = Coord::generateRandomCoordNotInCoords(*tmpMax, queue);
    this->coord = *coord;
}

Coord Apple::getCoord() {
    return coord;
}

void Apple::updateCoords(vector<Coord*>* queue) {
    Coord* coord = Coord::generateRandomCoordNotInCoords(*tmpMax, queue);
    this->coord = *coord;
}
