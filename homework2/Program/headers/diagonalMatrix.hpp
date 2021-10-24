#ifndef TASK1_DIAGONALMATRIX_HPP
#define TASK1_DIAGONALMATRIX_HPP

#include "commonSquare.hpp"
#include "utils.hpp"

class DiagonalMatrix : public CommonSquare {
public:
    virtual ~DiagonalMatrix();
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
