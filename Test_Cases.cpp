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
    for (const auto & row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    cout<<"Test Case 1\n";
    printMatrix(A, "A");
    printMatrix(B, "B");

    vector<vector<int>> resultAB = matrixMultiply(A, B);

    if (!resultAB.empty()) {
        printMatrix(resultAB, "C (A * B)");
    }

    vector<vector<int>> X = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> Y = {
        {10, 11, 12},
        {13, 14, 15}

    };
    cout<<"Test Case 2\n";
    printMatrix(X, "X");
    printMatrix(Y, "Y");

    vector<vector<int>> resultXY = matrixMultiply(X, Y);

    if (!resultXY.empty()) {
        printMatrix(resultXY, "Z (X * Y)");
    }
    return 0;
}
