#include "example.h"
Example::Example(Grid _grid) {
    Example::setGrid(_grid);
    Example::setGridN(_grid.getLen());
    Example::setExampleMatrix();
    Example::solveSystem();
}

void Example::setExampleMatrix() {
    Grid grid = Example::getGrid();
    int gridN = Example::getGridN();
    vector<vector<double>> matrix = Example::getMatrix();
    vector<double> f = Example::getF();
    vector<double> x = grid.getGridX();
    vector<double> phi = grid.getExamplePhi();
    double h = grid.getH();
    for (int i = 0; i < gridN; i++) {
        matrix.push_back({ });
        f.push_back(0);
        for (int j = 0; j < gridN; j++) {
            matrix[i].push_back(0);
        }
    }

    matrix[0][0] = (-k(0.5) - BETA1 * h);
    matrix[0][1] = k(0.5);
    f[0] = -MU1 * h;
    matrix[gridN - 1][gridN - 2] = k(0.5);
    matrix[gridN - 1][gridN - 1] = (-k(0.5) - BETA2 * h);
    f[gridN - 1] = -MU2 * h;

    for (int i = 1; i < gridN - 1; i++) {
        matrix[i][i - 1] = k(0.5);
        matrix[i][i] = (-k(0.5) - k(0.5) - q(0.5) * h * h);
        matrix[i][i + 1] = k(0.5);
        f[i] = -phi[i] * h * h;
    }
    Example::setF(f);
    Example::setMatrix(matrix);
}


