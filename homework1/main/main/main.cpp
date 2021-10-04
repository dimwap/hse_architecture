#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "container.h"
#include "Matrix.h"
#include "SimpleMatrix.h"

std::vector<int> SplitLine(std::string line) {
    int i = 0;
    std::vector<int> res;
    std::string cur = "";
    while (i < line.size()) {
        if (line[i] == ' ') {
            res.push_back(std::stoi(cur));
            cur = "";
        }
        else {
            cur += line[i];
        }
        i++;
    }
    res.push_back(std::stoi(cur));
    return res;
}

int main() {

    std::cout << "Введите имя файла с исходными матрицами:";
    std::string inputFileName;
    std::cin >> inputFileName;

    std::cout << "Введите имя файла для вывода результата:";
    std::string outputFileName;
    std::cin >> outputFileName;

    Container cont = Container();

    std::vector<std::string> lines;
    std::string line;

    std::ifstream in(inputFileName); 
    if (in.is_open())
    {
        while (getline(in, line))
        {
            lines.push_back(line);
        }
    }
    in.close();

    int i = 0;
    while (i < lines.size()) {
        int typeOfMatrix = std::stoi(lines[i]);
        int demension = std::stoi(lines[i + 1]);

        if (typeOfMatrix == 1) {
            std::vector<std::vector<int>> curArr;
            for (int j = i + 2; j < i + 2 + demension; ++j) {
                std::string newLine = lines[j];
                std::vector<int> curVec = SplitLine(newLine);
                curArr.push_back(curVec);
            }
            cont.AddMatrix(curArr, 1);
            i += 2 + demension;
        }
        else if (typeOfMatrix == 2) {
            std::string newLine = lines[i + 2];
            std::vector<int> curArr = SplitLine(newLine);
            cont.AddArr(curArr, 2, demension);
            i += 3;
        }
        else {
            std::string newLine = lines[i + 2];
            std::vector<int> curArr = SplitLine(newLine);
            cont.AddArr(curArr, 3, demension);
            i += 3;
        }
    }

    cont.PrintInformation(outputFileName);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}

