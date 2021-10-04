#include "Matrix.h"

class SimpleMatrix : Matrix {

public:
    std::string name;
    double middle;
    std::vector<std::vector<int>> array;
    SimpleMatrix(std::vector<std::vector<int>> arr, int demension) : Matrix(demension) {
        this->name = "Обычный двумерный массив.  Среднее значение:";
        this->array = arr;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr[i].size(); ++j) {
                count++;
                sum += arr[i][j];
            }
        }
        this->middle = ((sum + 0.0) / count);
    }
};


