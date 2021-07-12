//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_HELPERS_H
#define P3_HELPERS_H

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

#endif //P3_HELPERS_H
