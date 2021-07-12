//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_ALGORITHMS_H
#define P3_ALGORITHMS_H

#include "Helpers.h"

using namespace std;

/// Shell Sort
/// \param arr - The values being sorted
/// \param size - The number of elements in arr

void shellSort(int arr[], int size) {
    vector<int> sequence = generateSedgewickSequence(size);
    for (auto gap: sequence) {
        for (int i = gap; i < size; i ++) {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

#endif //P3_ALGORITHMS_H
