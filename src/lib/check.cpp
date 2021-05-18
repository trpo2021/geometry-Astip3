#include "check.h"
bool check(string& expression, string& type) // Первоначальная проверка
{
    string iscircle = "circle"; // Проверка, что нам дан круг

    int sizeIsCircle = (int)iscircle.size();
    int sizeExpression = (int)expression.size();

    int i = 0;
    for (; i < sizeIsCircle && i < sizeExpression; i++) {
        if (tolower(expression[i])
            != iscircle[i]) { // Приводим наши буквы к маленьким, чтобы сравнить
                              // их
            return 0;
        }
    }
    type = iscircle;
    if (i != 6)
        return 0; // Проверка типа фигуры

    int count = 0;
    while (((expression[i]) == '(' && !isdigit(expression[i]))
           && i < sizeExpression) { // Проверяем количество скобок
        count++;
        ++i;
    }

    if ((expression[i - 1]) != '(' && expression[i - 1] != ' ')
        return 0;

    bool digit = 0;
    for (; expression[i] != ')' && i < sizeExpression; i++) {
        // Проверяем цифры, запятые, точки (функция парсера не возьмет
        // данные с запятой, нужны с точкой)
        if (!isdigit(expression[i]) && expression[i] != '.'
            && expression[i] != ',' && expression[i] != ' ') {
            return 0;
        } else {
            if (isdigit(expression[i])) {
                digit = 1;
            }
            if (expression[i] == ',') {
                digit = 0;
            }
        }
    }
    if (!digit)
        return 0;

    while ((expression[i] != ' ' || !isdigit(expression[i])) && i < sizeExpression) { 
        // Проверяем скобки, но уже закрывающиеся
        if ((expression[i]) != ')') {
            return 0;
        }
        count--;
        ++i;
    }
    if (count)
        return 0; // Если скобок не хватает
    return 1;
}

