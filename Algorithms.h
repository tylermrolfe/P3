//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_ALGORITHMS_H
#define P3_ALGORITHMS_H

#include "Helpers.h"

using namespace std;

enum Sequence { Sedgewick, Hibbard };

/// Shell Sort
/// \param arr - The values being sorted
/// \param size - The number of elements in arr
/// \param seq - The Sequence used for the gap to sort
void shellSort(int arr[], int size, Sequence seq) {
    vector<int> sequence;
    switch (seq) {
        case Sedgewick: sequence = generateSedgewickSequence(size);
        case Hibbard: sequence = generateHibbardSequence(size);
    }
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
