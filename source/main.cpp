#include "grid.h"
#include "linSys.h"

int main() {
    Grid grid(X1, X2, N);
    LinSystem linSys(grid);
    printMatrix(linSys.getMatrix());
    printVector(linSys.getU());
    cout << "k(0.5) = " << k(0) << endl;
    cout << "q(0.5) = " << q(0) << endl;
    cout << "f(0.5) = " << f(0) << endl;
    linSys.compareSolutions();
    return 0;
}
