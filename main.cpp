#include <iostream>
#include "Matrix/Matrix.h"
#include <cstring>

using namespace matrix;

int scanInt(int&, const char*);

int main() {
    int n = -1, m = -1;
    const char* msg = "";
    while(n <= 0) {
        while(true) {
            std::cout << msg << std::endl;
            if(scanInt(n, "Enter count of rows: ") != -1) break;
            msg = "!!!You need enter positive number!!!";
        }
    }
    msg = "";
    while(m <= 0) {
        while(true) {
            std::cout << msg << std::endl;
            if (scanInt(m, "Enter count of counts: ") != -1) break;
            msg = "!!!You need enter positive number!!!\n";
        }
    }

    Matrix* matrix = getMatrix(n, m);

    std::cout << "Now you need to enter elements of matrix" << std::endl;
    while(true) {
        msg = "";
        while(true) {
            std::cout << msg << std::endl;
            if (scanInt(n, "Enter index of row or -1 for end input: ") != -1) break;
            msg = "!!!You need enter number!!!";
        }
        if(n <= 0) break;
        msg = "";
        while(true) {
            std::cout << msg << std::endl;
            if (scanInt(m, "Enter index of column or -1 for end input: ") != -1) break;
            msg = "!!!You need enter number!!!";
        }
        if(m <= 0) break;
        int data;
        while(true) {
            std::cout << msg << std::endl;
            if (scanInt(data, "Enter data of cell: ") != -1) break;
            msg = "!!!You need enter number!!!";
        }
        std::cout << "(" << n << "," << m << ") -> " << data << std::endl;
        addCell(n, m, data, matrix);
    }
    std::cout << "Source matrix" << std::endl;
    printMatrix(matrix);
    Matrix* r = result(matrix);
    std::cout << "Result matrix" << std::endl;
    printMatrix(r);
    freeMatrix(matrix);
    freeMatrix(r);
    return 0;
}

int scanInt(int& n, const char* msg){
    std::cout << msg << std::endl;
    char *input = new char[256];
    std::cin.getline(input, 256);
    char* ptr;
    n = (int) strtol(input, &ptr, 10);
    if(strlen(input) == 0 || ptr != input + strlen(input)){
        delete[] input;
        return -1;
    }
    delete[] input;
    return 0;
}
