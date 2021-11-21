#include "grid.h"

Grid::Grid(double x1, double x2, int n) {
    Grid::h = (x2 - x1) / n;
    for (int i = 0; i <= n; i++) {
        gridX.push_back(x1 + i * h);
        gridPhi.push_back(f(x1 + i *h));
        examplePhi.push_back(f(0.5));
        example.push_back(exampleSolution(x1 + i * h));
    }
    len = gridX.size();
}
Grid::Grid() {

}
vector <double> Grid::getGridX() {
    return gridX;
}

vector <double> Grid::getGridPhi() {
    return gridPhi;
}

vector<double> Grid::getExample() {
    return example;
}

double Grid::getH() {
    return h;
}

int Grid::getLen() {
    return len;
}