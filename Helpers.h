//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_HELPERS_H
#define P3_HELPERS_H

#include<cmath>

using namespace std;

enum DataType{ Latitude, Longitude, WaterDepth, OBSVNTop, OBSVNBot, Gravel, Sand, Mud, Clay, GrainSize, Sorting, MunsColr, OrgCarbn, Porosity};

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

/// Genereates the Sedgewick, 1982 Sequence for gaps with worst case time complexity of O(n^4/3)
/// \param size - The size of the array you are attempting to shell sort
/// \return
vector<int> generateSedgewickSequence(int size) {
    vector<int> sequence;
    int val = 1;
    int index = 1;
    sequence.push_back(val);
    while (val < size) {
        val = int(((pow(4, index) + (3*pow(2, index-1) + 1))));
        sequence.push_back(val);
        index++;
    }
    return sequence;
}

/// Genereates the Hibbard Sequence for gaps with worst case time complexity of O(n^3/2)
/// \param size - The size of the array you are attempting to shell sort
/// \return
vector<int> generateHibbardSequence(int size) {
    vector<int> sequence;
    int val = 0;
    int index = 1;
    while (val < size) {
        val = int((pow(2, index) - 1));
        sequence.push_back(val);
        index++;
    }
    return sequence;
}

float ArrayType(Sample arr[], int index, DataType& type) {
    switch (type) {
        case Latitude: return arr[index].latitude;
        case Longitude: return arr[index].longitude;
        case WaterDepth: return arr[index].waterDepth;
        case OBSVNTop: return arr[index].obsvnTop;
        case OBSVNBot: return arr[index].obsvnBot;
        case Gravel: return arr[index].gravel;
        case Sand: return arr[index].sand;
        case Mud: return arr[index].mud;
        case Clay: return arr[index].clay;
        case GrainSize: return arr[index].grainSize;
        case Sorting: return arr[index].sorting;
        case OrgCarbn: return arr[index].orgCarbn;
        case Porosity: return arr[index].porosity;
    }
}

#endif //P3_HELPERS_H
