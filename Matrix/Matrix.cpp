#include "Matrix.h"
#include <iostream>

namespace matrix{
    Matrix* getMatrix(int n, int m){
        auto* matrix = new Matrix();
        matrix->head = nullptr;
        matrix->n = n;
        matrix->m = m;
        return matrix;
    }

    int addCell(int x, int y, int data, Matrix* matrix){
        if(x*y < 0 || x > matrix->n || y > matrix->m)
            throw std::invalid_argument("Out of range");

        if(matrix->head == nullptr){
            matrix->head = new Row();
            matrix->head->index = x;
            matrix->head->head = new Cell();
            matrix->head->tail = matrix->head->head;
            matrix->head->head->index = y;
            matrix->head->head->data = data;
            matrix->head->next = nullptr;
            matrix->head->head->next = nullptr;
        } else {
            Row* buf = matrix->head;
            while(buf->next != nullptr && buf->index != x)
                buf = buf->next;
            if(buf->index != x){
                buf->next = new Row();
                buf = buf->next;
                buf->index = x;
                buf->head = new Cell();
                buf->tail = buf->head;
                buf->next = nullptr;
                buf->head->index = y;
                buf->head->data = data;
                buf->head->next = nullptr;
            } else {
                if(y < buf->head->index){
                    Cell* h = new Cell();
                    h->index = y;
                    h->data = data;
                    h->next = buf->head;
                    buf->head = h;
                } else {
                    Cell* h = buf->head;
                    while(h->next != nullptr && h->next->index < y)
                        h = h->next;
                    if(h->next == nullptr){
                        h->next = new Cell();
                        h = h->next;
                        h->next = nullptr;
                        h->index = y;
                        h->data = data;
                        buf->tail = h;
                    } else {
                        Cell* c = new Cell();
                        c->next = h->next;
                        h->next = c;
                        c->index = y;
                        c->data = data;
                    }
                }
            }

        }
        return 0;
    }

    int getSumDigit(int n){
        if(n < 0) n *= -1;
        int sum = 0;
        while(n != 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int getSumLast(const Matrix* matrix, int row){
        Row* head = matrix->head;
        while(head != nullptr && head->index != row)
            head = head->next;

        if (head == nullptr) return 0;

        return getSumDigit(head->tail->data);
    }

    void printMatrix(const Matrix* matrix){
        if(matrix->head == nullptr)
            std::cout << "Matrix is empty" << std::endl;
        else {
            Row *head = matrix->head;
            while (head != nullptr) {
                Cell *tmp = head->head;
                while (tmp != nullptr) {
                    std::cout << "(" << tmp->index << "," << head->index << ")->" << tmp->data << std::endl;
                    tmp = tmp->next;
                }
                head = head->next;
            }
        }
    }

    Matrix* result(const Matrix* matrix){
        Matrix* r = getMatrix(matrix->n, matrix->m);
        Row* row = matrix->head;
        while(row != nullptr){
            Cell* cell = row->head;
            int n = getSumLast(matrix, row->index);
            while(cell != nullptr){
                int m = getSumDigit(cell->data);
                if(m == n){
                    addCell(cell->index, row->index, cell->data, r);
                }
                cell = cell->next;
            }
            row = row->next;
        }
        return r;
    }

    void freeMatrix(Matrix* matrix){
        Row* row = matrix->head;
        while(row != nullptr){
            Row* tr = row;
            Cell* cell = tr->head;
            while(cell != nullptr){
                Cell* tc = cell;
                cell = cell->next;
                delete tc;
            }
            row = row->next;
            delete tr;
        }
    }
}
