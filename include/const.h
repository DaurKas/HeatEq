#ifndef CONST_H 
#define CONST_H

#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;



extern int N;
extern double BETA1;
extern double BETA2;
extern double MU1;
extern double MU2;
extern double EPS;
extern double X1;
extern double X2;



double k(double x);

double q(double x);

double f(double x);

double exampleSolution(double x);
#endif