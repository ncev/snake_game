#ifndef COORD_H
#define COORD_H
#include <iostream>
#include <vector>
#include "random.h"

using namespace std;

class Coord
{
public:
    Coord();
    Coord(int x, int y);
    int x;
    int y;
};

#endif // COORD_H
