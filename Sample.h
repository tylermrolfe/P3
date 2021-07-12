//
// Created by Tyler Rolfe on 7/11/21.
//

#ifndef P3_SAMPLE_H
#define P3_SAMPLE_H

#include <string>

using namespace std;

class Sample {
private:
    float latitude;
    float longitude;
    int waterDepth;
    float obsvnTop;
    float obsvnBot;
    int gravel;
    int sand;
    int mud;
    int clay;
    float grainSize;
    float sorting;
    // We should consider converting this into it's separate components
    string munslColr;
    float orgCarbn;
    int porosity;
public:
    Sample(float latitude, float longitude, int waterDepth, float obsvnTop, float obsvnBot, int gravel, int sand, int mud, int clay, float grainSize, float sorting, string& munslColr, float orgCarbn, int porosity);
};


#endif //P3_SAMPLE_H
