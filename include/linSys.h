#ifndef LINSYS_H
#define LINSYS_H
#include "grid.h"
vector<double> sweepMethod (vector<vector<double>> A, vector<double> F, int N);
vector<vector<double>> getMatrix(vector<double> & f);
void printMatrix(vector<vector<double>> A);
void printVector(vector<double> vec);

#endif