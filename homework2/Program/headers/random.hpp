#ifndef TASK1_RANDOM_HPP
#define TASK1_RANDOM_HPP

#include <stdlib.h>
#include "stdint.h"

class Random {
public:
    static int32_t next(int32_t lower = 0, int32_t upper = INT32_MAX);
};

#endif
