#include "Matrix.h"

class Diagonal : Matrix {


public:
    std::string name;
    double middle;
    std::vector<std::vector<int>> array;
    Diagonal(std::vector<int> arr, int demension) : Matrix(demension) {
        this->name = "Диагональная матрица. Среднее значение:";
        int count = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            std::vector<int> newVec;
            for (int j = 0; j < arr.size(); ++j) {
                if (i == j) {
                    newVec.push_back(arr[i]);
                    sum += arr[i];
                }
                else
                    newVec.push_back(0);
                count++;
            }
            array.push_back(newVec);
        }
        this->middle = ((sum + 0.0) / count);
    }
};
