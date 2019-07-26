#include "random.h"
Random* Random::instance;

Random::Random()
{

}

Random* Random::get_instance() {
    if (instance == nullptr)
        instance = new Random();
    return instance;
}

int Random::generateBetween(int min, int max) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_variable = std::rand();
    random_variable = min + ( random_variable % ( max - min + 1 ) );
    return random_variable;
}

int Random::generateBetweenNotEqualTo(int min, int max, int nb) {
    int n = nb;
    while (n == nb)
        n = generateBetween(min, max);
    return n;
}
