//
// Created by Marc Perlas on 7/11/21.
//

#include "Sample.h"

Sample::Sample(float latitude, float longitude, int waterDepth, float obsvnTop, float obsvnBot, int gravel,
               int sand, int mud, int clay, float grainSize, float sorting, string& munslColr, float orgCarbn,
               int porosity) {
    this->latitude = latitude;
    this->longitude = longitude;
    this->waterDepth = waterDepth;
    this->obsvnTop = obsvnTop;
    this->obsvnBot = obsvnBot;
    this->gravel = gravel;
    this->sand = sand;
    this->mud = mud;
    this->clay = clay;
    this->grainSize = grainSize;
    this->sorting = sorting;
    this->munslColr = munslColr;
    this->orgCarbn = orgCarbn;
    this->porosity = porosity;

}
