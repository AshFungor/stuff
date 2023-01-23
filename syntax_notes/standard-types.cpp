#include <iostream>
#include <climits> // файл с ограничениями типов


int main(void) {

    using std::cout;
    using std::endl;

    int example = 0; // любая целочисленная константа имеет тип int по умолчанию

    /*
     *  можно так (стиль инициализации класса):
     *  int example{0}
     *  int example = {0}
     *  можно, но не нужно так:
     *  int example(0);
     *
    */

    example = 1L; // эта константа имеет тип long
    example = 1LL; // аналогично, но long long


    double d_example = 0; // любая константа с плавающей точкой имеет тип double по умолчанию
    d_example = 1.0f; // константа float
    d_example = 1.0L; // long double



    cout << "so here is the example: \n";
    (cout << example) << endl;
    (cout << "here is an another d_example: \n" << d_example) << endl;

    // перегруженная операция битового сдвига для объекта cout помещает правый операнд в поток вывода и возвращает cout

    d_example = 1.1e7;
    /*
     *
     * экспоненциальная запись.
     * число с плавающей точкой храниться как стандартный вид числа, т.е:
     * 1.1 (мантисса) и 10^7 (порядок)
     *
     * примеры:
     * 1.23e+9, 1.23e-9, 1e-9 -> число = мантисса * 10 ^ (порядок)
     *
     *
    */

    // некоторые ограничения стандартных типов, зависят от системы
    cout << INT_MAX  << " "
         << LONG_MAX << " " << LONG_LONG_MAX
         << sizeof (double) << " " << sizeof (float); // sizeof (тип) или sizeof (object) или sizeof object

    cout << endl << "size of example is - " << sizeof example;


    return 0;

}
