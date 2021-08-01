//
// Created by Marc Perlas on 7/11/21.
//

#ifndef P3_SAMPLE_H
#define P3_SAMPLE_H

#include <string>

using namespace std;

class Sample {
public:
    float latitude;
    float longitude;
    float waterDepth;
    float obsvnTop;
    float obsvnBot;
    float gravel;
    float sand;
    float mud;
    float clay;
    float grainSize;
    float sorting;
    // We should consider converting this into it's separate components
    string munslColr;
    float orgCarbn;
    float porosity;

    Sample();
    Sample(float latitude, float longitude, float waterDepth, float obsvnTop, float obsvnBot, float gravel, float sand, float mud, float clay, float grainSize, float sorting, string& munslColr, float orgCarbn, float porosity);
};


#endif //P3_SAMPLE_H
