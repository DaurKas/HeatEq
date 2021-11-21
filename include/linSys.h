#ifndef LINSYS_H
#define LINSYS_H
#include "grid.h"

class LinSystem {
    int gridN;
    Grid grid;
    vector<double> f;
    vector <double> u;
    vector<vector<double>> matrix;
public:
    LinSystem (Grid _grid);
    LinSystem();

    void solveSystem();
    void preciseEval();
    void printSolution();

    int getGridN();
    Grid getGrid();
    vector<double> getF();
    vector<double> getU();
    vector<vector<double>> getMatrix();

    void setGridN(int _gridN);
    void setGrid(Grid _grid);
    void setF(vector<double> _f);
    void setU(vector<double> _u);
    void setMatrix(vector<vector<double>> _matrix);
    void calculateMatrix();
};
vector<double> sweepMethod (vector<vector<double>> A, vector<double> F, int N);
void printMatrix(vector<vector<double>> A);
void printVector(vector<double> vec);
void compareSolutions(vector<double> v1, vector<double> v2, Grid grid);

#endif