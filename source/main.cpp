#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

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
vector<vector<double>> getMatrix(vector<double> & f) {
    int N = 0;
    double value = 0;
    ifstream fin("input.txt");
    fin >> N;
    vector<vector<double>> A(N, vector<double> (N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j ++) {
            fin >> A[i][j];
        }    
    }
    for (int i = 0; i < N; i++) {
        fin >> value;
        f.push_back(value);
    }
    fin.close();
    return A;
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

int main() {
    vector<double> f;
    vector<double> y;
    vector<vector<double>> A = getMatrix(f);
    int N = f.size();
    printVector(f);
    cout << endl;
    printMatrix(A);
    y = sweepMethod(A, f, N);
    printVector(y);
    return 0;
}
