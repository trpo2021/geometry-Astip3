#include "calculate.h"

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
