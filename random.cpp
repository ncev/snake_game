#include "random.h"
Random* Random::instance;

Random::Random()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

Random* Random::get_instance() {
    if (instance == nullptr)
        instance = new Random();
    return instance;
}

int Random::generateBetween(int min, int max) {

    int random_variable = std::rand();
    random_variable = min + ( random_variable % ( max - min + 1 ) );
    return random_variable;
}
