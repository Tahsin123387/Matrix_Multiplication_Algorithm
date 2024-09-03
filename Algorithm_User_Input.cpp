#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    // Check if matrices can be multiplied
    if (colsA != rowsB) {
        cerr << "The two matrices can't be multiplied because the number of columns in the first matrix doesn't match the number of rows in the second matrix.\n" << endl;
        return {};  // Return an empty vector if matrices can't be multiplied
    }

    // Initialize the result matrix with zeros
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << "Matrix " << name << ":\n";
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions and values for matrix A
    cout << "Enter dimensions for matrix A (rows cols): ";
    cin >> rowsA >> colsA;
    vector<vector<int>> A(rowsA, vector<int>(colsA));
    cout << "Enter elements for matrix A:\n";
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    // Input dimensions and values for matrix B
    cout << "Enter dimensions for matrix B (rows cols): ";
    cin >> rowsB >> colsB;
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements for matrix B:\n";
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }
    
    printMatrix(A, "A");
    printMatrix(B, "B");

    vector<vector<int>> resultAB = matrixMultiply(A, B);

    if (!resultAB.empty()) {
        printMatrix(resultAB, "C (A * B)");
    }

    return 0;
}
