#ifndef GRID_H
#define GRID_H
#include "const.h"

class Grid {
    vector<double> gridX;
    vector<double> gridPhi;
    int len;
public:
    Grid(double x1, double x2, int n);
    vector<double> getGridX();
    vector<double> getGridPhi();
    double getEl(int i, int j);
};

#endif