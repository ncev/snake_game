#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <map>
#include "coord.h"

class Snake
{
private:
    vector<Coord*>* queue;
    Coord* max;
    bool end;
    map<string, void (*) (Coord*)> queueMov;
    string queueChange;
public:
    Snake(Coord* max);
    ~Snake();
    vector<Coord*>* getQueue();
    bool isEnded();
    void setEnded(bool end);
    void loopMovement(string keyboardTouch, long sec);
    bool checkQueuePos();
    void updateQueuePos();

    static void queueRight(Coord* coord);
    static void queueLeft(Coord* coord);
    static void queueUp(Coord* coord);
    static void queueDown(Coord* coord);
};

#endif // SNAKE_H
