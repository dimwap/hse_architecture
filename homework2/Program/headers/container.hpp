#ifndef TASK1_CONTAINER_HPP
#define TASK1_CONTAINER_HPP

#include <stdio.h>
#include "commonSquare.hpp"
#include "container.hpp"
#include "stdlib.h"

class Container {
public:
    Container();
    ~Container();

    void In(FILE *inputFile);
    void InRnd(size_t size);
    void Out(FILE *outputFile);

    void shakeSort();
    void swap(size_t idx1, size_t idx2);
private:
    void Clear();

    size_t len;
    CommonSquare *storage[10001];
};

#endif