#ifndef LAB1_1_MATRIX_H
#define LAB1_1_MATRIX_H


namespace matrix {
    struct Cell{
        int index, data;
        Cell* next;
    };

    struct Row{
        int index;
        Cell *head, *tail;
        Row* next;
    };

    struct Matrix{
        Row* head;
        int n, m;
    };

    Matrix* getMatrix(int, int);
    int addCell(int, int, int, Matrix*);
    int getSumDigit(int);
    int getSumLast(const Matrix*, int);
    void printMatrix(const Matrix*);
    Matrix* result(const Matrix*);
    void freeMatrix(Matrix*);
}

#endif //LAB1_1_MATRIX_H
