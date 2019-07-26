#include "apple.h"

Apple::Apple(Coord max)
{
    Random* rand = Random::get_instance();
    coord.x = rand->generateBetweenNotEqualTo(0, 25, max.x / 2);
    coord.y = rand->generateBetweenNotEqualTo(0, 19, max.y / 2);
    cout << coord.x << endl;
}

Coord Apple::getCoord() {
    return coord;
}
