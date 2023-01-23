#include <iostream>
#include <cstring>

// шаблонные и не очень функции

// пример

template <typename T>
void Swap(T&, T&); // template уникален для каждого объявления и прототипа

template <typename T>
void Swap(T*, T*);

template <> void Swap<char>(char* a, char* b); // спецификация



using std::cout;

int main(void) {

    int a = 1, b = 2;
    double c = 1.1, d = 3.4;

    cout << "a = " << a << ", b = " << b << std::endl
         << "c = " << c << ", d = " << d << std::endl;

    Swap(a, b); // компилятор генерирует уникальную функцию для каждого запрошенного типа
    Swap(c, d);

    cout << "a = " << a << ", b = " << b << std::endl
         << "c = " << c << ", d = " << d << std::endl;

    char* str_1 = new char[20];
    char* str_2 = new char[20];

    std::cin >> str_1 >> str_2;


    cout << str_1 << ' ' << str_2 << std::endl;

    Swap(str_1, str_2);

    cout << str_1 << ' ' << str_2 << std::endl;

    delete[] str_1, str_2;

    return 0;
}

template <typename T> void Swap(T& a, T& b) {

    T temp = a;
    a = b;
    b = temp;

}

template <typename T> void Swap(T* ptr_a, T* ptr_b) {

    T temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;


}

template <> void Swap<char>(char* a, char* b) {

    char* temp = new char[strlen(a)];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);

    delete[] temp;
}
