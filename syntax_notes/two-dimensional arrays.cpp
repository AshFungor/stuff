#include <iostream>

#define ALTERNATIVE

int main(void){

    using namespace std;

    // динамические двумерные массивы

    const int row_count = 4, column_count = 2;

    #ifndef ALTERNATIVE

    int** rows = new int*[4]; // указатель на массив указателей на int
    for (int i = 0; i < row_count; ++i)
        rows[i] = new int[column_count]; // создание столбцов

    #endif

    // можно так
    #ifdef ALTERNATIVE

    int** rows = new int*[row_count];
    rows[0] = new int[column_count] {0, 0};
    rows[1] = new int[column_count] {0, 1};
    rows[2] = new int[column_count] {0, 2};
    rows[3] = new int[column_count] {1, 2};




    #endif

    for (int row = 0; row < row_count; ++row) {
        for (int column = 0; column < column_count; ++column) { // вложенные циклы для итерации по двумерным массивам

            cout << "row is " << row << " column is " << column << " value is " << (rows[row][column] = row * column) << endl;
        }

    delete[] rows[row];

    }


    delete[] rows;
        
    

    return 0;
}
