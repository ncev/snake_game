#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

class Random
{
private:
    Random();
    static Random* instance;

public:
    static Random* get_instance();
    int generateBetween(int min, int max);
};

#endif // RANDOM_H
