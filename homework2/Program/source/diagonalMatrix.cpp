#include "../headers/diagonalMatrix.hpp"

void DiagonalMatrix::clear() {
    for (size_t i = 0; i < size; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    cells = nullptr;
    size = 0;
}

void DiagonalMatrix::init(size_t size) {
    this->size = size;
    cells = new int32_t*[size];
    for (size_t i = 0; i < size; i++) {
        cells[i] = new int32_t[size];
        for (size_t j = 0; j < size; j++) {
            cells[i][j] = 0;
        }
    }
}

DiagonalMatrix::~DiagonalMatrix() {
    clear();
}

size_t DiagonalMatrix::getSize() {
    return size;
}

double DiagonalMatrix::average() {
    double res = 0;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            res += cells[i][j];
        }
    }
    res /= (size * size);
    return res;
}

void DiagonalMatrix::inRnd() {
    this->clear();
    this->init((size_t)Random::next(2, 10));

    for (size_t i = 0; i < size; i++) {
        cells[i][i] = Random::next(0, 1000);
    }
}

void DiagonalMatrix::in(FILE* inputFile) {
    int32_t num;
    readInt(inputFile, num);
    init((size_t) num);

    for (size_t i = 0; i < size; i++) {
        readInt(inputFile, cells[i][i]);
    }
}

void DiagonalMatrix::out(FILE* outputFile) {
    fprintf(outputFile, "%d\n", (int32_t)size);
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - 1; j++) {
            fprintf(outputFile, "%d ", cells[i][j]);
        }
        fprintf(outputFile, "%d\n", cells[i][size - 1]);
    }
}