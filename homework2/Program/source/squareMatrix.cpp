#include "../headers/squareMatrix.hpp"

void SquareMatrix::clear() {
    for (size_t i = 0; i < size; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;
    size = 0;
}

void SquareMatrix::init(size_t size) {
    this->size = size;
    cells = new int32_t*[size];
    for (size_t i = 0; i < size; i++) {
        cells[i] = new int32_t[size];
        for (size_t j = 0; j < size; j++) {
            cells[i][j] = 0;
        }
    }
}

SquareMatrix::~SquareMatrix() {
    clear();
}

size_t SquareMatrix::getSize() {
    return size;
}

double SquareMatrix::average() {
    double res = 0;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            res += cells[i][j];
        }
    }
    res /= (size * size);
    return res;
}

void SquareMatrix::inRnd() {
    this->clear();
    this->init((size_t)Random::next(2, 10));

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cells[i][j] = Random::next(0, 1000);
        }
    }
}

void SquareMatrix::in(FILE* inputFile) {
    int32_t num;
    readInt(inputFile, num);
    init((size_t) num);

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            readInt(inputFile, cells[i][j]);
        }
    }
}

void SquareMatrix::out(FILE* outputFile) {
    fprintf(outputFile, "%lu\n", size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            fprintf(outputFile, "%d ", cells[i][j]);
        }
        fprintf(outputFile, "%d\n", cells[i][size - 1]);
    }
}