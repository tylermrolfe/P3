//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_ALGORITHMS_H
#define P3_ALGORITHMS_H

#include "Helpers.h"

using namespace std;

enum Sequence { Sedgewick, Hibbard };
enum DataType{ Latitude, Longitude, WaterDepth, OBSVNTop, OBSVNBot, Gravel, Sand, Mud, Clay, GrainSize, Sorting, MunsColr, OrgCarbn, Porosity};

/// Shell Sort
/// \param arr - The values being sorted
/// \param size - The number of elements in arr
/// \param seq - The Sequence used for the gap to sort
/// \param type - The data type the user requested -- See the enum type DataType for options
void shellSort(Sample arr[], int size, Sequence seq, DataType type) {
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
                case MunsColr: for (j = i; j >= gap && arr[j - gap].munslColr > temp.munslColr; j -= gap) { arr[j] = arr[j - gap]; } break;
                case OrgCarbn: for (j = i; j >= gap && arr[j - gap].orgCarbn > temp.orgCarbn; j -= gap) { arr[j] = arr[j - gap]; } break;
                case Porosity: for (j = i; j >= gap && arr[j - gap].porosity > temp.porosity; j -= gap) { arr[j] = arr[j - gap]; } break;
            }

            arr[j] = temp;

        }
    }
}



#endif //P3_ALGORITHMS_H
