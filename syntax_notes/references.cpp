#include <iostream>

using std::cout;

//  ссылки
int& example_func(int arg_1, int& arg_2);

int main(void) {

    int example;

    int& ref_example = example; // ссылка (псевдоним) example

    int* const ptr_example = &example; // аналогичный ссылке указатель, но его надо разыменовывать

    example_func(example, example) = 12; // так можно в случае с ссылками

    cout << example << std::endl;

    return 0;
}

int& example_func(int arg_1, int& arg_2) {

    cout << "adress of arg_1 is " << &arg_1 << std::endl;
    cout << "adress of arg_2 is " << &arg_2 << std::endl; // arg_2 это example

    arg_2 = 0;
    cout << arg_2 << std::endl;

    return arg_2;


}

