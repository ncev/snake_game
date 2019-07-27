#include "apple.h"

Apple::Apple(Coord* max, vector<Coord*>*)
{
    Random* rand = Random::get_instance();
    int notX[3];
    int notY[3];

    notX[0] = max->getX() / 2;
    notY[0] = max->getY() / 2;

    for (int i = 1; i != 3; ++i) {
        notX[i] = notX[i - 1];
        notY[i] = notY[i - 1];
    }

    coord.setX(rand->generateBetweenNotEqualTo(0, 25, notX, 3));
    coord.setY(rand->generateBetweenNotEqualTo(0, 19, notY, 3));
}

Coord Apple::getCoord() {
    return coord;
}
