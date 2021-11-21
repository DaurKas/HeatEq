#ifndef RUNGE_H
#define RUNGE_H
#include <linSys.h>

LinSystem rungeApprox(LinSystem linSys, int n0);
double calcDiff(LinSystem solution1, LinSystem solution2);


#endif