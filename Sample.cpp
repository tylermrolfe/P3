//
// Created by Marc Perlas on 7/11/21.
//

#include "Sample.h"

Sample::Sample(float latitude, float longitude, float waterDepth, float obsvnTop, float obsvnBot, float gravel,
               float sand, float mud, float clay, float grainSize, float sorting, string& munslColr, float orgCarbn,
               float porosity) {
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

Sample::Sample() {
    this->latitude = 0.0;
    this->longitude = 0.0;
    this->waterDepth = 0;
    this->obsvnTop = 0.0;
    this->obsvnBot = 0.0;
    this->gravel = 0;
    this->sand = 0;
    this->mud = 0;
    this->clay = 0;
    this->grainSize = 0.0;
    this->sorting = 0.0;
    this->munslColr = "";
    this->orgCarbn = 0.0;
    this->porosity = 0;
}
