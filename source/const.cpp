#include "const.h"
int N = 100;
double BETA1 = 0;
double BETA2 = 1;
double MU1 = 0;
double MU2 = 0;
double EPS = 0.01;
double X1 = 0;
double X2 = 1;

double k(double x) {
    //return exp(0.5);
    return exp(x);
}

double q(double x) {
    //return exp(0.5);
    return exp(x);
}

double f(double x) {
    //return sin(0.5);
    return sin(x);
}

double exampleSolution(double x) {
    return (-0.0418) * exp(x) + (-0.0418) * exp(-x) + 0.29079;
}
