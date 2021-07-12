//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_HELPERS_H
#define P3_HELPERS_H

#include<cmath>

using namespace std;

/// Supports int and float types to determine if parameter is undefined per the documentation
///
/// Returns true if the type is undefined
template <typename T>
bool isUndefined(T val) {
    if (val == -99 || val == -99.0) {
        return true;
    } else {
        return false;
    }
}

vector<int> generateSedgewickSequence(int size) {
    vector<int> sequence;
    int val = 1;
    int index = 1;
    sequence.push_back(val);
    while (val < size) {
        val = ((pow(4, index) + (3*pow(2, index-1) + 1)));
        sequence.push_back(val);
        index++;
    }
    return sequence;
}

#endif //P3_HELPERS_H
