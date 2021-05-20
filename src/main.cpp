#include "lib/check.h"
#include "lib/parse.h"
#include "lib/calculate.h"

#include <cmath>
#include <iostream>
#include <string>
#include <vector> // Вектор (замена массиву, куда мы сложим спарсенные данные)

using namespace std;


int main()
{
    string expression;        // Наше исходное выражение
    getline(cin, expression); // Вввод выражения
    vector<double> v;         // Сюда парсятся наши данные
    string type;              // Тип фигуры
    if (!(check(expression, type) && parse(expression, v, type)
          && calculate(
                  expression,
                  v,
                  type))) { // Если три функции возвращают 1, то завершаем
                            // программу, иначе идем в цикл
        do {
            cout << "ERROR!" << endl;
            getline(cin, expression);
        } while (
                !(check(expression, type) && parse(expression, v, type)
                  && calculate(
                          expression,
                          v,
                          type))); // Вводим выражение заново, пока не добьемся
                                   // нужного результата
    }

    return 0;
}