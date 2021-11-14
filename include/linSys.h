#ifndef LINSYS_H
#define LINSYS_H
#include "grid.h"

class LinSystem {
    Grid grid;
    vector<double> f;
    vector <double> u;
    vector<vector<double>> matrix;
public:
    LinSystem (Grid _grid);
    void setMatrix();
    vector<vector<double>> getMatrix();
    vector<double> getU();
    void solveSystem();
    void compareSolutions();
    void preciseEval();
    
};
vector<double> sweepMethod (vector<vector<double>> A, vector<double> F, int N);
void printMatrix(vector<vector<double>> A);
void printVector(vector<double> vec);

#endif