#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <map>
#include "coord.h"
#include "apple.h"

class Snake
{
private:
    vector<Coord*>* queue;
    Apple* apple;
    Coord* max;
    bool end;
    map<string, void (*) (Coord*)> queueMov;
    string queueChange;
    bool requireIncreaseOnQueue;
public:
    Snake(Coord* max);
    ~Snake();
    vector<Coord*>* getQueue();
    bool isEnded();
    void setEnded(bool end);
    void loopMovement(string keyboardTouch, long sec);
    bool checkQueuePos();
    void updateQueuePos();
    void updateQueueDir(string queueChange);
    void setApple(Apple* apple);
    int getScore();

    static void queueRight(Coord* coord);
    static void queueLeft(Coord* coord);
    static void queueUp(Coord* coord);
    static void queueDown(Coord* coord);
};

#endif // SNAKE_H
