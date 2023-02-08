#include "functions.h"

int Random_int(int lower_bound, int upper_bound)
{
    std::random_device rd;                                           // obtain a random number from hardware
    std::mt19937 gen(rd());                                          // seed the generator
    std::uniform_int_distribution<> distr(lower_bound, upper_bound); // define the range

    return distr(gen);
}
