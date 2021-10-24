#include "../headers/commonSquare.hpp"
#include "../headers/diagonalMatrix.hpp"
#include "../headers/squareMatrix.hpp"
#include "../headers/triangleDownMatrix.hpp"

CommonSquare* CommonSquare::StaticIn(FILE *inputFile) {
    int32_t matrix_type;
    if (!readInt(inputFile, matrix_type)) {
        return nullptr;
    }

    CommonSquare *instance = nullptr;
    switch (matrix_type) {
        case 1:
            instance = new SquareMatrix;
            break;
        case 2:
            instance = new DiagonalMatrix;
            break;
        case 3:
            instance = new TriangleDownMatrix;
            break;
        default:
            instance = new DiagonalMatrix;
            break;
    }
    instance->in(inputFile);

    return instance;
}

CommonSquare* CommonSquare::StaticInRnd() {
    int32_t choice = Random::next(1, 4);
    CommonSquare *instance = nullptr;
    switch (choice) {
        case 1:
            instance = new SquareMatrix;
            break;
        case 2:
            instance = new DiagonalMatrix;
            break;
        case 3:
            instance = new TriangleDownMatrix;
            break;
        default:
            instance = new DiagonalMatrix;
            break;
    }
    instance->inRnd();
    return instance;
}
