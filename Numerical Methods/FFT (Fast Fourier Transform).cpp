#include <iostream>
#include <vector>

using namespace std;

// Function to perform LU decomposition
void luDecomposition(vector<vector<double>>& A) {
    int n = A.size();

    // L and U matrices
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    // Implement LU Decomposition here

    // Print L and U for demonstration
    cout << "L Matrix:" << endl;
    // Print L

    cout << "U Matrix:" << endl;
    // Print U
}

int main() {
    // Example usage
    vector<vector<double>> A = {{2, -1, -2}, {-4, 6, 3}, {-4, -2, 8}};
    luDecomposition(A);

    return 0;
}
