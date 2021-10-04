#include <vector>
#include "Matrix.h"
#include "SimpleMatrix.h"
#include "TriangleMatrix.h"
#include "Diagonal.h"
#include <iostream>
#include <fstream>

class Container {
    static int const maxLen = 10000;
    int curLen = 0;
    std::vector<SimpleMatrix> matrixesArr2d;
    std::vector<Diagonal> matrixesDiagonal;
    std::vector<TriangleMatrix> matrixesLowMatrix;

public:
    void AddMatrix(std::vector<std::vector<int>> arr, int typeOfMatrix) {
        matrixesArr2d.push_back(SimpleMatrix(arr, arr.size()));
        curLen++;
    }

    void AddArr(std::vector<int> arr, int typeOfMatrix, int demension) {
        if (typeOfMatrix == 2) {
            matrixesDiagonal.push_back(Diagonal(arr, demension));
            curLen++;
        }
        else {
            matrixesLowMatrix.push_back(TriangleMatrix(arr, demension));
            curLen++;
        }
    }

    void swap(double* a, double* b) {
        double temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    void ShakerSort(double a[], int m) {
        int i, j, k;
        for (i = 0; i < m;) {
            for (j = i + 1; j < m; j++) {
                if (a[j] < a[j - 1])
                    swap(&a[j], &a[j - 1]);
            }
            m--;
            for (k = m - 1; k > i; k--) {
                if (a[k] < a[k - 1])
                    swap(&a[k], &a[k - 1]);
            }
            i++;
        }
    }

    void PrintInformation(std::string outputFileName) {
        std::ofstream out;          
        out.open(outputFileName); 
        if (out.is_open())
        {
            out << "Количество матриц: " << curLen << std::endl;
            out << "Матрицы: " << std::endl;
            std::vector<double> toSort;
            for (int i = 0; i < matrixesArr2d.size(); ++i) {
                out << matrixesArr2d[i].name << " " << matrixesArr2d[i].middle << std::endl;
                toSort.push_back(matrixesArr2d[i].middle);
                for (int j = 0; j < matrixesArr2d[i].array.size(); ++j) {
                    for (int k = 0; k < matrixesArr2d[i].array[j].size(); ++k) {
                        out << matrixesArr2d[i].array[j][k] << " ";
                    }
                    out << std::endl;
                }
                out << std::endl;
            }

            for (int i = 0; i < matrixesDiagonal.size(); ++i) {
                out << matrixesDiagonal[i].name << " " << matrixesDiagonal[i].middle << std::endl;
                toSort.push_back(matrixesDiagonal[i].middle);
                for (int j = 0; j < matrixesDiagonal[i].array.size(); ++j) {
                    for (int k = 0; k < matrixesDiagonal[i].array[j].size(); ++k) {
                        out << matrixesDiagonal[i].array[j][k] << " ";
                    }
                    out << std::endl;
                }
                out << std::endl;
            }

            for (int i = 0; i < matrixesLowMatrix.size(); ++i) {
                out << matrixesLowMatrix[i].name << " " << matrixesLowMatrix[i].middle << std::endl;
                toSort.push_back(matrixesLowMatrix[i].middle);
                for (int j = 0; j < matrixesLowMatrix[i].array.size(); ++j) {
                    for (int k = 0; k < matrixesLowMatrix[i].array[j].size(); ++k) {
                        out << matrixesLowMatrix[i].array[j][k] << " ";
                    }
                    out << std::endl;
                }
                out << std::endl;
            }

            double* arr = new double[toSort.size()];
            ShakerSort(arr, toSort.size());
            for (int i = 0; i < toSort.size(); i++) {
                out<<( arr[i])<<" ";
            }
        }

        std::cout << "Конец программы" << std::endl;
    }


};
