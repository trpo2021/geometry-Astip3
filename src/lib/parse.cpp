#include "parse.h"

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

