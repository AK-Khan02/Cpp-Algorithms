#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> subtractProjection(const vector<double>& u, const vector<double>& v) {
    double dotProduct = inner_product(u.begin(), u.end(), v.begin(), 0.0);
    double normU = inner_product(u.begin(), u.end(), u.begin(), 0.0);
    vector<double> result(v.size(), 0);
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] - (dotProduct / normU) * u[i];
    }
    return result;
}

void gramSchmidt(vector<vector<double>>& A) {
    size_t n = A.size();  // Assuming A is square for simplicity
    vector<vector<double>> Q(n, vector<double>(n, 0));

    // First normalized vector q1
    double norm = sqrt(inner_product(A[0].begin(), A[0].end(), A[0].begin(), 0.0));
    for (size_t j = 0; j < n; ++j) {
        Q[j][0] = A[j][0] / norm;
    }

    for (size_t i = 1; i < n; ++i) {
        Q[i] = A[i];
        for (size_t j = 0; j < i; ++j) {
            Q[i] = subtractProjection(Q[j], Q[i]);
        }
        norm = sqrt(inner_product(Q[i].begin(), Q[i].end(), Q[i].begin(), 0.0));
        for (size_t j = 0; j < n; ++j) {
            Q[j][i] = Q[j][i] / norm;
        }
    }

    // Print the orthogonalized vectors (Q matrix)
    cout << "Orthogonalized Vectors (Q Matrix):" << endl;
    for (const auto& row : Q) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<double>> A = {{1, 1, 0}, {1, 0, 1}, {0, 1, 1}};
    gramSchmidt(A);
    return 0;
}
