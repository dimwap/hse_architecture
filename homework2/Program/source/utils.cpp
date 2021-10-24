#include "../headers/utils.hpp"

bool readInt(FILE* inputFile, int32_t& number) {
    int count = fscanf(inputFile, "%d", &number);
    if (count == EOF || count == 0) {
        number = 0;
        return false;
    }
    return true;
}