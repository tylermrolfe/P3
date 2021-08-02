#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Sample.h"
#include "Helpers.h"
#include "Algorithms.h"
using namespace std;

int main() {

    // Constants
    const string SAMPLE_DATA = "Project3data.csv";
    const int SAMPLE_SIZE = 181546;
    const int UNDEFINED = -99;

    ifstream inFile(SAMPLE_DATA);

    string inputData;
    getline(inFile, inputData);

    string latitude, longitude, waterDepth, obsvnTop, obsvnBot, gravel, sand, mud, clay, grainSize, sorting, munslColr, orgCarbn, porosity;

    auto *samples = new Sample[SAMPLE_SIZE];

    int index = 0;

    while (getline(inFile, inputData)) {
        istringstream stream(inputData);
        getline(stream, latitude, ',');
        getline(stream, longitude, ',');
        getline(stream, waterDepth, ',');
        getline(stream, obsvnTop, ',');
        getline(stream, obsvnBot, ',');
        getline(stream, gravel, ',');
        getline(stream, sand, ',');
        getline(stream, mud, ',');
        getline(stream, clay, ',');
        getline(stream, grainSize, ',');
        getline(stream, sorting, ',');
        getline(stream, munslColr, ',');
        getline(stream, orgCarbn, ',');
        getline(stream, porosity, ',');

        Sample log(stof(latitude), stof(longitude), stof(waterDepth), stof(obsvnTop),
                   stof(obsvnBot), stof(gravel), stof(sand), stof(mud), stof(clay), stof(grainSize),
                   stof(sorting), munslColr, stof(orgCarbn), stof(porosity));

        samples[index] = log;
        index++;
    }

    int valueType = 0;
    int sortType = 0;
    DataType result;

    cout << "Welcome to the Camparison of Sediment Rates on the Coast of the US and its Territories Program! \n";

    cout << "Choose what to sort by! \n";
    cout << "1. Latitude\n2. Longitude\n3. Water Depth\n4. Gravel\n5. Sand\n6. Mud\n7. Clay\n8. Grain Size\n9. Standard Deviation of Grain Size in Sample\n10. Percent Carbon\n11. Porosity\n";

    while (valueType < 1 || valueType > 11) {
        cin >> valueType;
        switch (valueType) {
            case 1: result = Latitude; break;
            case 2: result = Longitude; break;
            case 3: result = WaterDepth; break;
            case 4: result = Gravel; break;
            case 5: result = Sand; break;
            case 6: result = Mud; break;
            case 7: result = Clay; break;
            case 8: result = GrainSize; break;
            case 9: result = Sorting; break;
            case 10: result = OrgCarbn; break;
            case 11: result = Porosity; break;
            default: cout << "Please choose a valid response!\n"; valueType = 12; break;
        }
        if (valueType == 12) {
            continue;
        }
    }

    cout << "\nChoose how to Sort!\n";
    cout << "1. Merge Sort\n2. Quick Sort\n3. Shell Sort\n";

    while (sortType < 1 || sortType > 3) {
        cin >> sortType;
        switch (sortType) {
            case 1: {
                auto t1 = Clock::now();
                mergeSort(samples, 0, SAMPLE_SIZE, result);
                auto t2 = Clock::now();
                cout << "The Merge Sort took " << duration_cast<nanoseconds>(t2 - t1).count() << " nano seconds to run." << endl;
                break;
            }
            case 2: {
                auto t1 = Clock::now();
                QuickSort(samples, 0, SAMPLE_SIZE - 1, result);
                auto t2 = Clock::now();
                cout << "The Quick Sort took " << duration_cast<seconds>(t2 - t1).count() << " seconds to run." << endl;
                break;
            }
            case 3:
                cout << "Which sequence do you want to use?\n";
                cout << "1. Sedgewick\n2. Hibbard\n";
                while (sortType < 1 || sortType > 2) {
                    cin >> sortType;
                    switch (sortType) {
                        case 1: shellSort(samples, SAMPLE_SIZE, Sedgewick, result); break;
                        case 2: shellSort(samples, SAMPLE_SIZE, Hibbard, result); break;
                        default: cout << "Please choose a valid response!\n"; break;
                    }
                }
                break;
                default: cout << "Please choose a valid response!\n"; break;
        }
    }

//    for (int i = SAMPLE_SIZE - 1; i >= 100; i--) {
//        cout << fixed << showpoint;
//        cout << setprecision(2);
//        cout << ArrayType(samples, i, result) << " ";
//    }

    cout << endl;

    float searchVal;
    string tempStr;

    cout << "Choose a value of your type " << "to search for!" << endl;
    cin >> tempStr;
    searchVal = stof(tempStr);
    index = Search(samples, 0, SAMPLE_SIZE - 1, searchVal, result);
    //index = Search(samples, 0, SAMPLE_SIZE - 1, searchVal, result);
    if (searchVal == UNDEFINED) {
        cout << "Sorry, there is no sample corresponding to this value. Goobye!" << endl;
    }
    else {
        cout << "Latitude: " << samples[index].latitude << endl;
        cout << "Longitude: " << samples[index].longitude << endl;
        cout << "Water Depth: " << samples[index].waterDepth << endl;
        cout << "Observation Top: " << samples[index].obsvnTop << endl;
        cout << "Observation Bottom: " << samples[index].obsvnBot << endl;
        cout << "Gravel: " << samples[index].gravel << endl;
        cout << "Sand: " << samples[index].sand << endl;
        cout << "Mud: " << samples[index].mud << endl;
        cout << "Clay: " << samples[index].clay << endl;
        cout << "Grain Size: " << samples[index].grainSize << endl;
        cout << "Sorting: " << samples[index].sorting << endl;
        cout << "Organic Carbon Ratio: " << samples[index].orgCarbn << endl;
        cout << "Porosity: " << samples[index].porosity << endl;
        cout << endl;
        cout << "Here are similar samples and their locations!" << endl;
        cout << "Latitude: " << samples[index + 1].latitude << " Longitude: " << samples[index + 1].longitude << endl;
        cout << "Latitude: " << samples[index - 1].latitude << " Longitude: " << samples[index - 1].longitude << endl;
        cout << endl;
        cout << endl;
    }

    return 0;
}

//Citation for Shell Sort sequences
//Source: https://en.wikipedia.org/wiki/Shellsort
//Use: Source for conceptualization of shell sort sequences
