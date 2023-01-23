#include <iostream>
#include <cmath>

// шаблоны part 2

template <typename T1, typename T2> auto sum(T1 a, T2 b) -> decltype (a + b);

int main(void) {

    int a = 5; double b = 6.;

    /* на этапе определения sum тип возвращаемого значения неизвестен,
     * поэтому используется trailing return type (хвостовой возвращаемый тип)
     * синтаксис:
     * auto NAME(ARGS) -> TYPE (пример - sum)
     *
    */

    // при сложении int и double int расширяется до double - возв. тип будет double

    double res = sum(a, b);

    std::cout << res << std::endl;

    return 0;
}

template <typename T1, typename T2> auto sum(T1 a, T2 b) -> decltype (a + b) {

    // decltype (выражения) -> возвращает тип выражения, удобен для инициализации
    // пример

    decltype (a + b) res = a + b;
    decltype (sqrt(a + b)) square_res = sqrt(a + b);

    // decltype () можно использовать с typedef
    // пример

    typedef decltype (a + b) res_type;

    res_type _res = a + b;

    std::cout << res << ' ' << square_res
              << ' ' << _res << std::endl;

    return a + b;
}
