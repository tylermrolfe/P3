//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_ALGORITHMS_H
#define P3_ALGORITHMS_H
#include "Helpers.h"
#include <chrono>

using namespace std::chrono;

typedef high_resolution_clock Clock;

enum Sequence { Sedgewick, Hibbard };

/// Shell Sort
/// \param arr - The values being sorted
/// \param size - The number of elements in arr
/// \param seq - The Sequence used for the gap to sort
/// \param type - The data type the user requested -- See the enum type DataType for options
void shellSort(Sample arr[], int size, Sequence seq, DataType type) {
    auto t1 = Clock::now();
    vector<int> sequence;
    switch (seq) {
        case Sedgewick: sequence = generateSedgewickSequence(size);
        case Hibbard: sequence = generateHibbardSequence(size);
    }
    for (auto& gap: sequence) {
        for (int i = gap; i < size; i++) {
            Sample temp = arr[i];

            int j;
            switch (type) {
                case Latitude: for (j = i; j >= gap && arr[j - gap].latitude > temp.latitude; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Longitude: for (j = i; j >= gap && arr[j - gap].longitude > temp.longitude; j -= gap) { arr[j] = arr[j - gap]; } break;
                case WaterDepth: for (j = i; j >= gap && arr[j - gap].waterDepth > temp.waterDepth; j -= gap) { arr[j] = arr[j - gap]; } break;
                case OBSVNTop: for (j = i; j >= gap && arr[j - gap].obsvnTop > temp.obsvnTop; j -= gap) { arr[j] = arr[j - gap]; } break;
                case OBSVNBot: for (j = i; j >= gap && arr[j - gap].obsvnBot > temp.obsvnBot; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Gravel: for (j = i; j >= gap && arr[j - gap].gravel > temp.gravel; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Sand: for (j = i; j >= gap && arr[j - gap].sand > temp.sand; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Mud: for (j = i; j >= gap && arr[j - gap].mud > temp.mud; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Clay: for (j = i; j >= gap && arr[j - gap].clay > temp.clay; j -= gap) { arr[j] = arr[j - gap]; } break;
                case GrainSize: for (j = i; j >= gap && arr[j - gap].grainSize > temp.grainSize; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Sorting: for (j = i; j >= gap && arr[j - gap].sorting > temp.sorting; j -= gap) { arr[j] = arr[j - gap]; } break;
                case OrgCarbn: for (j = i; j >= gap && arr[j - gap].orgCarbn > temp.orgCarbn; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Porosity: for (j = i; j >= gap && arr[j - gap].porosity > temp.porosity; j -= gap) { arr[j] = arr[j - gap]; } break;
                default: break;
            }

            arr[j] = temp;
        }
    }
    auto t2 = Clock::now();
    switch (seq) {
        case Hibbard: cout << "The Shell sort via Hibbard sequence took " << duration_cast<seconds>(t2 - t1).count() << " seconds to run." << endl; break;
        case Sedgewick: cout << "The Shell sort via Sedgewick sequence took " << duration_cast<seconds>(t2 - t1).count() << " seconds to run." << endl; break;
    }
}

/// Partitions the array used in Quick Sort based off the first elemet in the array
int PartitionArray(Sample arr[], int startPoint, int endPoint, DataType type) {
    unsigned int i = startPoint;
    float partitionPoint;
    float arrUp;
    float arrDown;
    int up;
    int down;

    partitionPoint = ArrayType(arr, i, type);

    up = i + 1;
    down = endPoint;
    arrUp = ArrayType(arr, up, type);
    arrDown = ArrayType(arr, down, type);

    while (up < down) {
        while (arrUp <= partitionPoint && up < endPoint) {
            up++;
            arrUp = ArrayType(arr, up, type);
        }
        while (arrDown >= partitionPoint && down > startPoint) {
            down--;
            arrDown = ArrayType(arr, down, type);
        }
        if (up < down) {
            swap(arr[up], arr[down]);
            arrUp = ArrayType(arr, up, type);
            arrDown = ArrayType(arr, down, type);
        }
    }
    if (arrDown <= partitionPoint && down != i) {
        swap(arr[i], arr[down]);
        return down;
    }
    return i;
}


//Quick Sort
/// \param arr - The values being sorted
/// \param size - The number of elements in arr
/// \param startingPoint - the starting point of the section actively being sorted
/// \param endPoint - the end point of the section actively being sorted
/// \param type - The data type the user requested -- See the enum type DataType for options
void QuickSort(Sample arr[], int startingPoint, int endPoint, DataType type) {
    int partitionPoint;

    if (startingPoint < endPoint) {
        partitionPoint = PartitionArray(arr, startingPoint, endPoint, type); //Clay
        QuickSort(arr, startingPoint, partitionPoint - 1, type);
        QuickSort(arr, partitionPoint + 1, endPoint, type);
    }
}


void merge(Sample samples[], int left, int middle, int right, DataType& type) {
    int subArrOne = middle - left + 1;
    int subArrTwo = right - middle;

    auto leftHalf = new Sample[subArrOne];
    auto rightHalf = new Sample[subArrTwo];


    // Copy items to temp arr
    for (int i = 0; i < subArrOne; i++) {
        leftHalf[i] = samples[left + i];
    }

    for (int j = 0; j < subArrTwo; j++) {
        rightHalf[j] = samples[middle + 1 + j];
    }

    int indexOne = 0;
    int indexTwo = 0;
    int indexMerged = left;

    // Merge temp arr back
    while (indexOne < subArrOne && indexTwo < subArrTwo) {
        switch (type) {
            case Latitude: {
                if (leftHalf[indexOne].latitude <= rightHalf[indexTwo].latitude) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Longitude: {
                if (leftHalf[indexOne].longitude <= rightHalf[indexTwo].longitude) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case WaterDepth: {
                if (leftHalf[indexOne].waterDepth <= rightHalf[indexTwo].waterDepth) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case OBSVNTop: {
                if (leftHalf[indexOne].obsvnTop <= rightHalf[indexTwo].obsvnTop) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case OBSVNBot: {
                if (leftHalf[indexOne].obsvnBot <= rightHalf[indexTwo].obsvnBot) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Gravel: {
                if (leftHalf[indexOne].gravel <= rightHalf[indexTwo].gravel) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Sand: {
                if (leftHalf[indexOne].sand <= rightHalf[indexTwo].sand) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Mud: {
                if (leftHalf[indexOne].mud <= rightHalf[indexTwo].mud) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Clay: {
                if (leftHalf[indexOne].clay <= rightHalf[indexTwo].clay) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case GrainSize: {
                if (leftHalf[indexOne].grainSize <= rightHalf[indexTwo].grainSize) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Sorting: {
                if (leftHalf[indexOne].sorting <= rightHalf[indexTwo].sorting) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case OrgCarbn: {
                if (leftHalf[indexOne].orgCarbn <= rightHalf[indexTwo].orgCarbn) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
            case Porosity: {
                if (leftHalf[indexOne].porosity <= rightHalf[indexTwo].porosity) {
                    samples[indexMerged] = leftHalf[indexOne];
                    indexOne++;
                }
                else {
                    samples[indexMerged] = rightHalf[indexTwo];
                    indexTwo++;
                }
                break;
            }
        } // end switch
        indexMerged++;
    }
    // Copy what's left into left arr
    while (indexOne < subArrOne) {
        samples[indexMerged] = leftHalf[indexOne];
        indexOne++;
        indexMerged++;
    }
    // Copy what's left into right arr
    while (indexTwo < subArrTwo) {
        samples[indexMerged] = rightHalf[indexTwo];
        indexTwo++;
        indexMerged++;
    }
}

void mergeSort(Sample samples[], int front, int back, DataType& type) {
    if (front >= back) {
        return;
    }

    int middle = front + (back - front) / 2;

    mergeSort(samples, front, middle, type);
    mergeSort(samples, middle + 1, back, type);
    merge(samples, front, middle, back, type);
}

// Binary Search implementation on a sorted array
int Search(Sample arr[], int starting, int ending, float x, DataType type) {
    if (ending >= starting) {
        int mid = starting + (ending - starting) / 2;

        if (ArrayType(arr, mid, type) == x) {
            return mid; // the index of the item in the array
        }

        if (ArrayType(arr, mid, type) > x) {
            return Search(arr, starting, mid - 1, x, type);
        }

        return Search(arr, mid + 1, ending, x, type);
    }

    return -99;
}

#endif //P3_ALGORITHMS_H
