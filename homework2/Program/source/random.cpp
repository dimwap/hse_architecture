#include "../headers/random.hpp"

int32_t Random::next(int32_t lower, int32_t upper) {
    if (lower < upper) {
        return rand() % (upper - lower) + lower;
    }
    return 0;
}

