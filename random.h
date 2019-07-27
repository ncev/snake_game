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
    int generateBetweenNotEqualTo(int min, int max, int nb[], int size);
};

#endif // RANDOM_H
