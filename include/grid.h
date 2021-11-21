#ifndef GRID_H
#define GRID_H
#include "const.h"

class Grid {
    vector<double> gridX;
    vector<double> gridPhi;
    vector<double> examplePhi;
    vector<double> example;
    double h;
    int len;
public:
    Grid(double x1, double x2, int n);
    Grid();
    vector<double> getGridX();
    vector<double> getGridPhi();
    vector<double> getExample();
    vector<double> getExamplePhi();
    double getH();
    double getEl(int i, int j);
    int getLen();
};

#endif