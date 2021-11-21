#include "runge.h"

LinSystem rungeApprox(LinSystem linSys, int n0) {
    int curN = 2 * n0;
    LinSystem linSys2 = linSys;
    Grid gridNext(X1, X2, curN);
    LinSystem linSysNext(gridNext);
    double diff = calcDiff(linSys2, linSysNext);
    while (diff > EPS) { 
        linSys2 = linSysNext;
        curN *= 2;
        gridNext = Grid(X1, X2, curN);
        linSysNext = LinSystem(gridNext);
        diff = calcDiff(linSys2, linSysNext);
    }
    return linSys2;
}

double calcDiff(LinSystem solution1, LinSystem solution2) { // n2 > n1
    Grid grid1 = solution1.getGrid();
    Grid grid2 = solution2.getGrid();
    vector<double> x1 = grid1.getGridX();
    vector<double> x2 = grid2.getGridX();
    vector<double> u1 = solution1.getU();
    vector<double> u2 = solution2.getU();
    int n1 = solution1.getGridN();
    int n2 = solution2.getGridN();
    double maxDiff = 0;
    for (int i = 0; i < n1; i ++) {
        for (int j = 0; j < n2; j++) {
            if (x1[i] == x2[j]) {
                if (abs(u1[i] - u2[j]) > maxDiff) {
                    maxDiff = abs(u1[i] - u2[j]);
                    break;
                }
            }
        }
    }
    return maxDiff;
}
