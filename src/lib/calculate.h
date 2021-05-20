#ifndef CALCULATE_H_
#define CALCULATE_H_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const double PI = atan(1) * 4;

bool calculate(
        const string& expression, const vector<double>& nums, string& type);

#endif
