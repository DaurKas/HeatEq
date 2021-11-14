#include "linSys.h"

LinSystem::LinSystem(Grid _grid) {
    LinSystem::grid = _grid;
    LinSystem::setMatrix();
    LinSystem::solveSystem();
}

void LinSystem::setMatrix() {
    vector<double> x = grid.getGridX();
    vector<double> phi = grid.getGridPhi();
    double h = grid.getH();
    for (int i = 0; i < N; i++) {
        matrix.push_back({ });
        f.push_back(0);
        for (int j = 0; j < N; j++) {
            matrix[i].push_back(0);
        }
    }

    matrix[0][0] = (-k(X1) - BETA1 * h);
    matrix[0][1] = k(X1);
    f[0] = -MU1 * h;
    matrix[N - 1][N - 2] = k(X2);
    matrix[N - 1][N - 1] = (-k(X2) - BETA2 * h);
    f[N - 1] = -MU2 * h;

    for (int i = 1; i < N - 1; i++) {
        matrix[i][i - 1] = k(x[i]);
        matrix[i][i] = (-k(x[i + 1]) - k(x[i]) - q(x[i]) * h * h);
        matrix[i][i + 1] = k(x[i + 1]);
        f[i] = -phi[i] * h * h;
    }
}

void LinSystem::solveSystem() {
    u = sweepMethod(LinSystem::matrix, LinSystem::f, N);
}

vector<vector<double>> LinSystem::getMatrix() {
    return matrix;
}

vector<double> LinSystem::getU() {
    return u;
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

void LinSystem::compareSolutions() {
    vector<double> example = grid.getExample();
    vector<double> x = grid.getGridX();
    cout << "X(i)" << setw(8) << "U(x)" << setw(8) << "~U(x)" << setw(8) << "delta" << endl;
    for (int i = 0; i < N; i++) {
        cout << x[i] << "    " << u[i] << "  " << example[i] << " " << abs(u[i] - example[i]) << endl;
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