#ifndef COORD_H
#define COORD_H
#include <iostream>
#include <vector>
#include "random.h"

using namespace std;

class Coord
{
private:
    int* x;
    int* y;
public:
    Coord();
    Coord(int x, int y);
    ~Coord();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};

#endif // COORD_H
