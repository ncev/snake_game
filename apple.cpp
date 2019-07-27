#include "apple.h"

Apple::Apple(Coord* max, vector<Coord*>* coords)
{
    Coord* cord = Coord::generateRandomCoordNotInCoords(*max, coords);
    coord = *cord;
}

Coord Apple::getCoord() {
    return coord;
}
