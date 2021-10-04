#include "Matrix.h"

class TriangleMatrix : Matrix {

public:
    std::string name;
    double middle;
    std::vector<std::vector<int>> array;
    TriangleMatrix(std::vector<int> arr, int demension) : Matrix(demension) {
        this->name = "Среднее значение нижней треугольной матрицы:";
        int counter = 0;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < demension; ++i) {
            std::vector<int> newVec;
            for (int j = 0; j < demension; ++j) {
                if (j < demension && j < i + 1) {
                    newVec.push_back(arr[counter]);
                    sum += arr[counter];
                    counter++;
                }
                else
                    newVec.push_back(0);
                count++;
            }
            this->array.push_back(newVec);
        }
        this->middle = ((sum + 0.0) / count);
    }
};
