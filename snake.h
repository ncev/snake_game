#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "coord.h"

class Snake
{
private:
    vector<Coord*>* queue;
    Coord max;
    bool end;
public:
    Snake(Coord* max);
    ~Snake();
    vector<Coord*>* getQueue();
    bool isEnded();
    void setEnded(bool end);
    void loopMovement();
};

#endif // SNAKE_H
