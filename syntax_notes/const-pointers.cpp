#include <iostream>

using std::cout;

// #define EXAMPLE

// константные указатели и указатели на константные данные

int main(void) {


    int integer = 0;
    const int const_integer = 0;

    // const перед указателем запрещает изменение данных через указатель
    const int* const_n_ptr = &integer;


    // присваивать изменяемые данные константному указателю можно только при непосредственной ссылке на эти данные
    #ifdef EXAMPLE
    // пример
    const int** second_level_ptr;
    int* first_level_ptr;
    const int data = 1;

    second_level_ptr = &first_level_ptr; // константная ссылка на не константные данные (не разрешено при таком уровне абстракции)

    *second_level_ptr = &data; // не константная ссылка на константные данные (what?)

    *first_level_ptr = 10; // dead by compiling time LOL

    #endif

    int* const n_const_ptr = &integer;
    // константный указатель нельзя изменить (т.е. заставить ссылаться на константные данные)

    // к - комбо
    const int* const const_n_const_ptr = &const_integer;

    cout << "just to establish dominance: " << *const_n_const_ptr << " got a pointer - " << std::hex << const_n_const_ptr << std::endl;


    return 0;
}
