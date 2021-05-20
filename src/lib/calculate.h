#ifndef CALCULATE_H_
#define CALCULATE_H_

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = atan(1) * 4; 


bool calculate(
        const string& expression,
        const vector<double>& nums,
        string& type);

#endif
