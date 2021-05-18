#include <cmath>
#include <iostream>
#include <string>
#include <vector> // Вектор (замена массиву, куда мы сложим спарсенные данные)


#include "parse.h"
#include "check.h"

using namespace std;

const double PI = atan(1) * 4; // Определим pi

bool calculate(
        const string& expression,
        const vector<double>& nums,
        string& type) // Производим рассчеты
{
    if (type == "circle"
        && nums.size()
                == 3) { // Проверяем количество данных и тип, дальше рассчеты
        system("cls");
        cout << expression << endl;
        cout << "perimeter = " << 2 * PI * nums[2] << endl;
        cout << "area = " << PI * pow(nums[2], 2) << endl;
    }
    return 1;
}

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