#include <iostream>

using std::cout;

const int ruler_len = 9;

void next(char* ruler);

int main(void) {

    char* ruler = new char[ruler_len + 1];

    for (int i = 1; i < ruler_len - 1; ++i)
        ruler[i] = ' ';

    ruler[0] = '|';
    ruler[ruler_len - 1] = '|';
    ruler[ruler_len] = 0;

    next(ruler);

    delete[] ruler;


    return 0;
}

void next(char* ruler) {

    int first = -1;

    if (ruler[0] == ruler[1])
        return;

    for (int i = 0; i < ruler_len; ++i) {
         
         if (ruler[i] == '|') {

             if (first == -1) {

                 first = i;
             }

             else {

                 ruler[(first + i) / 2] = '|';
                 first = i;
             }
         }
    }

    cout << ruler << std::endl;
    next(ruler);

}

