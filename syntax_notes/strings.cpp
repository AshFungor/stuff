#include <iostream>
#include <cstring>

// строки
int main(void) {

    using std::cout;
    using std::endl;
    using std::string;

    // строка - последовательность символов, оканчивающихся на \0 (нулевой символ)
    char c_str[20] = {"hello, world!"};
    // все незаполненные участки памяти массива устанавливаются в \0

    for (int index = 0; index < 20; ++index) {

        cout << "character " << index << " is " << *(c_str + index) << " ("
             << int(c_str[index]) << ") " << endl;

    }

    cout << "enter a string: ";
    std::cin.getline(c_str, 20);
    // получаем строку до \n
    // cout << c_str << endl;

    cout << "enter a string: ";
    // или так
    std::cin.get(c_str, 20); // этот метод хуже т.к. сохраняет \n
    // cout << c_str << endl;

    string str; // шаблонный класс string (удобней)

    cout << "enter a string: "; std::cin >> str;

    cout << str.capacity() << " " << str.length() << endl; // ...и еще много методов для работы

    cout << "enter a string: " << endl;
    getline(std::cin, str); // получить строку до \n
    cout << str << endl;

    
    return 0;

}
