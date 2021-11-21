#include "linSys.h"

LinSystem::LinSystem(Grid _grid) {
    LinSystem::grid = _grid;
    LinSystem::gridN = _grid.getLen();
    LinSystem::calculateMatrix();
    LinSystem::solveSystem();
}

LinSystem::LinSystem() {

}

void LinSystem::calculateMatrix() {
    vector<double> x = grid.getGridX();
    vector<double> phi = grid.getGridPhi();
    double h = grid.getH();
    for (int i = 0; i < gridN; i++) {
        matrix.push_back({ });
        f.push_back(0);
        for (int j = 0; j < gridN; j++) {
            matrix[i].push_back(0);
        }
    }
    double betaUp1 = BETA1 + 0.5 * h * q(X1);
    double betaUp2 = BETA2 + 0.5 * h * q(X2);
    double muUp1 = MU1 - 0.5 * h * phi[0];
    double muUp2 = MU2 - 0.5 * h * phi[gridN - 1];
    double a1 = k(x[0]) * 0.5 + 0.5 * k(x[1]);
    double aN = k(x[gridN - 2]) * 0.5 + k(x[gridN - 1]) * 0.5;

    matrix[0][0] = -1 * (a1 + betaUp1 * h);
    matrix[0][1] = a1;
    f[0] = -muUp1 * h;
    matrix[gridN - 1][gridN - 2] = aN;
    matrix[gridN - 1][gridN - 1] = -1 * (aN + betaUp2 * h);
    f[gridN - 1] = -1 * muUp2 * h;
/*
    matrix[0][0] = (-k(X1) - BETA1 * h);
    matrix[0][1] = k(X1);
    f[0] = -MU1 * h;
    matrix[gridN - 1][gridN - 2] = k(X2);
    matrix[gridN - 1][gridN - 1] = (-k(X2) - BETA2 * h);
    f[gridN - 1] = -MU2 * h;
*/
    for (int i = 1; i < gridN - 1; i++) {
        matrix[i][i - 1] = k(x[i]);
        matrix[i][i] = (-k(x[i + 1]) - k(x[i]) - q(x[i]) * h * h);
        matrix[i][i + 1] = k(x[i + 1]);
        f[i] = -phi[i] * h * h;
    }
}

void LinSystem::solveSystem() {
    u = sweepMethod(LinSystem::matrix, LinSystem::f, gridN);
}

vector<double> sweepMethod (vector<vector<double>> A, vector<double> F, int N) {
    double y;
    vector<double> a(N, 0);
    vector<double> B(N, 0);
    vector<double> result(N, 0);
    y = A[0][0];
    a[0] = -A[0][1] / y;
    B[0] = F[0] / y  ;
    for (int i = 1; i < N - 1; i++) {
        y = A[i][i] + A[i][i - 1] * a[i - 1];
        a[i] = -A[i][i + 1] / y;
        B[i] = (F[i] - A[i][i - 1] * B[i - 1]) / y;
    }
    result[N - 1] = (F[N - 1] - A[N - 1][N - 2] * B[N - 2]) / (A[N - 1][N - 1] + A[N - 1][N - 2] * a[N - 2]);
    for (int i = N - 2; i >= 0; i--) {
        result[i] = a[i] * result[i + 1] + B[i];
    }
    return result;
}

void compareSolutions(vector<double> v1, vector<double> v2, Grid grid) {
    int n = grid.getLen();
    vector<double> x = grid.getGridX();
    cout << "X(i)" << setw(8) << "U(x)" << setw(8) << "~U(x)" << setw(8) << "delta" << endl;
    for (int i = 0; i < n; i++) {
        cout << x[i] << "    " << v1[i] << "  " << v2[i] << " " << abs(v1[i] - v2[i]) << endl;
    }
}
void LinSystem::setGridN(int _gridN) {
    gridN = _gridN;
}
void LinSystem::setGrid(Grid _grid) {
    grid = _grid;

}
void LinSystem::setF(vector<double> _f) {
    f = _f;
}
void LinSystem::setU(vector<double> _u) {
    u = _u;
}
void LinSystem::setMatrix(vector<vector<double>> _matrix) {
    matrix = _matrix;
}

int LinSystem::getGridN() {
    return gridN;
}
Grid LinSystem::getGrid() {
    return grid;
}
 vector<double> LinSystem::getF() {
     return f;
}
 vector<double> LinSystem::getU() {
     return u;
}
 vector<vector<double>> LinSystem::getMatrix() {
     return matrix;
}
vector<double> Grid::getExamplePhi() {
    return examplePhi;
}
void LinSystem::printSolution() {
    vector<double> x = grid.getGridX();
    cout << "X_i    " << "U(x_i)" << endl;
    for (int i = 0; i < gridN; i++) {
        cout << x[i] << "    " << u[i] << endl;
    }
}
void printVector(vector<double> vec) {
    for (auto i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' ';
    cout << endl;
}

void printMatrix(vector<vector<double>> A) {
    for (size_t i = 0; i < A.size(); i++) {
        printVector(A[i]);
    }
}