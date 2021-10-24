#ifndef TASK1_COMMONSQUARE_HPP
#define TASK1_COMMONSQUARE_HPP

#include <cstdio>
#include "random.hpp"
#include <cstddef>

class CommonSquare {
public:
    virtual size_t getSize() = 0;
    virtual double average() = 0;

    virtual void in(FILE *inputFile) = 0;
    virtual void inRnd() = 0;
    virtual void out(FILE *inputFile) = 0;

    static CommonSquare *StaticIn(FILE *inputFile);
    static CommonSquare *StaticInRnd();
};


#endif