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
    static Coord* generateRandomCoord(Coord max);
    static Coord* generateRandomCoordNotInCoords(Coord max, vector<Coord*>* coordsNotIn);
};

#endif // COORD_H
