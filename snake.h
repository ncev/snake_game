#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "coord.h"

class Snake
{
private:
    vector<Coord*>* queue;
    Coord max;
public:
    Snake(Coord* coord);
    ~Snake();
    vector<Coord*>* getQueue();
};

#endif // SNAKE_H
