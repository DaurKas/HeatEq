#include "grid.h"
#include "linSys.h"

int main() {
    vector<double> f;
    vector<double> y;
    vector<vector<double>> A = getMatrix(f);
    int len = f.size();
    printVector(f);
    cout << endl;
    printMatrix(A);
    y = sweepMethod(A, f, len);
    printVector(y);
    cout << endl;
    Grid grid(0, 1, 100);
    printVector(grid.getGridPhi());
    return 0;
}
