#include "apple.h"

Apple::Apple(Coord* max, vector<Coord*>* coords)
{
    Coord tmpMax(max->getX() - 1, max->getY() - 1);
    Coord* cord = Coord::generateRandomCoordNotInCoords(tmpMax, coords);
    coord = *cord;
}

Coord Apple::getCoord() {
    return coord;
}
