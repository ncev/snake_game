#include "apple.h"

Apple::Apple(Coord max)
{
    Random* rand = Random::get_instance();
    coord.setX(rand->generateBetweenNotEqualTo(0, 25, max.getX() / 2));
    coord.setY(rand->generateBetweenNotEqualTo(0, 19, max.getY() / 2));
}

Coord Apple::getCoord() {
    return coord;
}
