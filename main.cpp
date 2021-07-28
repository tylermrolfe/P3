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

        Sample log(stof(latitude), stof(longitude), stoi(waterDepth), stof(obsvnTop),
                   stof(obsvnBot), stoi(gravel), stoi(sand), stoi(mud), stoi(clay), stof(grainSize),
                   stof(sorting), munslColr, stof(orgCarbn), stoi(porosity));

        samples[index] = log;
        index++;
    }

    cout << "Successfully created " << index << " objects!" << endl;

    shellSort(samples, SAMPLE_SIZE, Hibbard, Clay);

    for (int i = SAMPLE_SIZE; i > SAMPLE_SIZE-100; i--) {
        cout << samples[i].clay << " ";
    }

    return 0;
}
