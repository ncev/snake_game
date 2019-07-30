#ifndef APPLE_H
#define APPLE_H
#include "coord.h"
#include "random.h"

class Apple
{
private:
    Coord coord;
    Coord* tmpMax;
public:
    Apple(Coord* max, vector<Coord*>* queue);
    Coord getCoord();
    void updateCoords(vector<Coord*>* queue);
};

#endif // APPLE_H
