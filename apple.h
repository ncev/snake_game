#ifndef APPLE_H
#define APPLE_H
#include "coord.h"
#include "random.h"

class Apple
{
private:
    Coord coord;
public:
    Apple(Coord* max, vector<Coord*>* queue);
    Coord getCoord();
};

#endif // APPLE_H
