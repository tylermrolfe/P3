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
enum DataType{ Latitude, Longitude, WaterDepth, OBSVNTop, OBSVNBot, Gravel, Sand, Mud, Clay, GrainSize, Sorting, MunsColr, OrgCarbn, Porosity};

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
                case Latitude: { for (j = i; j >= gap && arr[j - gap].latitude > temp.latitude; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Longitude: { for (j = i; j >= gap && arr[j - gap].longitude > temp.longitude; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case WaterDepth: { for (j = i; j >= gap && arr[j - gap].waterDepth > temp.waterDepth; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case OBSVNTop: { for (j = i; j >= gap && arr[j - gap].obsvnTop > temp.obsvnTop; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case OBSVNBot: { for (j = i; j >= gap && arr[j - gap].obsvnBot > temp.obsvnBot; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Gravel: { for (j = i; j >= gap && arr[j - gap].gravel > temp.gravel; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Sand: { for (j = i; j >= gap && arr[j - gap].sand > temp.sand; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Mud: { for (j = i; j >= gap && arr[j - gap].mud > temp.mud; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Clay: { for (j = i; j >= gap && arr[j - gap].clay > temp.clay; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case GrainSize: { for (j = i; j >= gap && arr[j - gap].grainSize > temp.grainSize; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Sorting: { for (j = i; j >= gap && arr[j - gap].sorting > temp.sorting; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case MunsColr: { for (j = i; j >= gap && arr[j - gap].munslColr > temp.munslColr; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case OrgCarbn: { for (j = i; j >= gap && arr[j - gap].orgCarbn > temp.orgCarbn; j -= gap) { arr[j] = arr[j - gap]; } break; }
                case Porosity: { for (j = i; j >= gap && arr[j - gap].porosity > temp.porosity; j -= gap) { arr[j] = arr[j - gap]; } break; }
            }

            arr[j] = temp;
        }
    }
    auto t2 = Clock::now();
    switch (seq) {
        case Hibbard: cout << "The Shell sort via Hibbard sequence took " << duration_cast<seconds>(t2 - t1).count() << " nano seconds to run." << endl; break;
        case Sedgewick: cout << "The Shell sort via Sedgewick sequence took " << duration_cast<seconds>(t2 - t1).count() << " nano seconds to run." << endl; break;
    }
}

/// Partitions the array used in Quick Sort based off the first elemet in the array
int PartitionArray(Sample arr[], int size, DataType& type) {
    unsigned int i = 0;
    float partitionPoint;
    float arrUp;
    float arrDown;
    int up;
    int down;


    switch (type) {
        case Latitude: partitionPoint = arr[i].latitude; break;
        case Longitude: partitionPoint = arr[i].longitude; break;
        case WaterDepth: partitionPoint = arr[i].waterDepth; break;
        case OBSVNTop: partitionPoint = arr[i].obsvnTop; break;
        case OBSVNBot: partitionPoint = arr[i].obsvnBot; break;
        case Gravel: partitionPoint = arr[i].gravel; break;
        case Sand: partitionPoint = arr[i].sand; break;
        case Mud: partitionPoint = arr[i].mud; break;
        case Clay: partitionPoint = arr[i].clay; break;
        case GrainSize: partitionPoint = arr[i].grainSize; break;
        case Sorting: partitionPoint = arr[i].sorting; break;
        case OrgCarbn: partitionPoint = arr[i].orgCarbn; break;
        case Porosity: partitionPoint = arr[i].porosity; break;
    }

    while (isUndefined(partitionPoint)) {
        partitionPoint = arr[i++].clay;
    }
    up = i + 1;
    down = size - 1;

    while (up < down) {
        switch (type) {
            case Latitude: arrUp = arr[up].latitude; arrDown = arr[down].latitude; break;
            case Longitude: arrUp = arr[up].longitude; arrDown = arr[down].longitude; break;
            case WaterDepth: arrUp = arr[up].waterDepth; arrDown = arr[down].waterDepth; break;
            case OBSVNTop: arrUp = arr[up].obsvnTop; arrDown = arr[down].obsvnTop; break;
            case OBSVNBot: arrUp = arr[up].obsvnBot; arrDown = arr[down].obsvnBot; break;
            case Gravel: arrUp = arr[up].gravel; arrDown = arr[down].gravel; break;
            case Sand: arrUp = arr[up].sand; arrDown = arr[down].sand; break;
            case Mud: arrUp = arr[up].mud; arrDown = arr[down].mud; break;
            case Clay: arrUp = arr[up].clay; arrDown = arr[down].clay; break;
            case GrainSize: arrUp = arr[up].grainSize; arrDown = arr[down].grainSize; break;
            case Sorting: arrUp = arr[up].sorting; arrDown = arr[down].sorting; break;
            case OrgCarbn: arrUp = arr[up].orgCarbn; arrDown = arr[down].orgCarbn; break;
            case Porosity: arrUp = arr[up].porosity; arrDown = arr[down].porosity; break;
        }
        while (arrUp < partitionPoint) { //arrUp < partitionPoint
            up++;
        }
        while (arrDown > partitionPoint) { //arrDown > partitionPoint
            down--;
        }
        if (arrUp > arrDown) { //arrUp > arrDown
            swap(arr[up], arr[down]);
        }
    }
    swap(arr[i], arr[down]);
    return down;
}


//Quick Sort
/// \param arr - The values being sorted
/// \param size - The number of elements in arr
/// \param startingPoint - the starting point of the section actively being sorted
/// \param endPoint - the end point of the section actively being sorted
/// \param type - The data type the user requested -- See the enum type DataType for options
void QuickSort(Sample arr[], int size, int startingPoint, int endPoint, DataType& type) {
    int partitionPoint;

    if (startingPoint < endPoint) {
        partitionPoint = PartitionArray(arr, size, type); //Clay
        QuickSort(arr, size, startingPoint, partitionPoint, type);
        QuickSort(arr, size, partitionPoint + 1, endPoint, type);
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

#endif //P3_ALGORITHMS_H
