#include "grid.h"
#include "linSys.h"
#include "example.h"
#include "runge.h"

int main() {
    Grid grid(X1, X2, N);
    LinSystem linSys(grid);
    Example example(grid);
    linSys = rungeApprox(linSys, N);
    cout << "EXAMPLE COMPARISON:" << endl;
    compareSolutions(example.getU(), grid.getExample(), grid);
    cout << "COMMON SOLUTION:" << endl;
    linSys.printSolution();
    return 0;
}
