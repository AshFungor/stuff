#include <iostream>
#include <array-example.cpp>

using std::cout;

int& func(void);

extern int number; // one definition rule, - оспользование уже определенной переменной

int main(void) {

    cout << number << std::endl;

    auto arr = build(5, 1);

    for (int i = 0; i < arr.len; ++i)
        cout << arr.arr[i] << ' ';

    delete[] arr.arr;


    int& a = func();

    cout << std::endl << a << ' ';

    cout << (a = 5);


    return 0;
}

int& func(void) {

    static int a = 3; // static размещение - это глобальное (статическое) размещение данных

    return a;

}
