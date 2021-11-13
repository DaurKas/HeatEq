#include "const.h"
const int N = 1;
const double BETA1 = 0;
const double BETA2 = 1;
const double MU1 = 0;
const double MU2 = 0;
const double EPS = 0.01;

double k(double x) {
    return exp(x);
}

double q(double x) {
    return exp(x);
}

double f(double x) {
    return sin(x);
}
