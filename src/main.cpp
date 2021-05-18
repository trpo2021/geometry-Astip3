#include <cmath>
#include <iostream>
#include <string>
#include <vector> // Вектор (замена массиву, куда мы сложим спарсенные данные)

using namespace std;

const double PI = atan(1) * 4; // Определим pi

bool parse(string& expression, vector<double>& nums, string& type)
{
    string num; // Сюда закидываем число со строки

    int sizeExpression = (int)expression.size();

    int count = 0;
    for (int i = 0; i < sizeExpression; i++) {
        if (isdigit(expression[i]) || expression[i] == '.') {
            num.push_back(expression[i]); // По символу добавляем наше число до
                                          // запятой
        }
        if (expression[i] == ',' || expression[i] == ')'
            || expression[i] == ' ') {
            if (num.size() > 0) {
                nums.push_back(stod(num));
                num.clear();
                count++;
            } else {
                if (i + 1 == sizeExpression || expression[i] == ' ')
                    continue; // Смотрим пробелы или конец
                return 0;
            }
        }
        if (count == 2
            && expression[i]
                    == ',') { // Проверка на количество числе после запятой (у
                              // круга должно остаться одно число после
                              // последней запятой, у остальных 2
            count = 0;
        }
    }
    if ((count != 0 && type != "circle") || (count != 1 && type == "circle"))
        return 0; // Проверка круга или другой фигуры

    return 1;
}

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