#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Sample.h"
#include "Helpers.h"
#include "Algorithms.h"


int main() {

    // Constants
    const string SAMPLE_DATA = "Project3data.csv";
    const int SAMPLE_SIZE = 181546;
    const int UNDEFINED = -99;

    ifstream inFile(SAMPLE_DATA);

    string data;
    getline(inFile, data);

    string latitude, longitude, waterDepth, obsvnTop, obsvnBot, gravel, sand, mud, clay, grainSize, sorting, munslColr, orgCarbn, porosity;

    auto *samples = new Sample[SAMPLE_SIZE];

    int index = 0;

    while (getline(inFile, data)) {
        istringstream stream(data);
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
    //cout << "Successfully created " << index << " objects!" << endl;

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
            default: cout << "Please choose a valid response!\n"; break;
        }
    }

    cout << "\nChoose how to Sort!\n";
    cout << "1. Merge Sort\n2. Quick Sort\n3. Shell Sort\n";

    while (sortType < 1 || sortType > 3) {
        cin >> sortType;
        switch (sortType) {
            case 1:
                mergeSort(samples, 0, SAMPLE_SIZE, result); break;
            case 2: break;
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

    for (int i = SAMPLE_SIZE - 1; i >= 180000; i--) {
        cout << samples[i].mud << " ";
    }

    return 0;
}