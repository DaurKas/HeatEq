#include "grid.h"

Grid::Grid(double x1, double x2, int n) {
    double h = (x2 - x1) / n;
    for (int i = 0; i <= n; i++) {
        gridX.push_back(x1 + i * h);
        gridPhi.push_back(f(x1 + i *h));
    }
    len = gridX.size();
}

vector <double> Grid::getGridX() {
    return gridX;
}

vector <double> Grid::getGridPhi() {
    return gridPhi;
}
