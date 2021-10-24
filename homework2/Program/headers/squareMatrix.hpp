#ifndef TASK1_SQUAREMATRIX_HPP
#define TASK1_SQUAREMATRIX_HPP

#include "commonSquare.hpp"
#include "utils.hpp"

class SquareMatrix : public CommonSquare {
public:
    virtual ~SquareMatrix();
    virtual size_t getSize();
    virtual double average();

    virtual void in(FILE *inputFile);
    virtual void inRnd();
    virtual void out(FILE *inputFile);

    void clear();
    void init(size_t size);
private:
    int32_t **cells;
    size_t size;
};

#endif
