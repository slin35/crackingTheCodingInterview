#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* rotate the matrix 90 degrees */
void rotate90(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = i; j < matrix[i].size(); j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }

        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate90(matrix);
    printMatrix(matrix);

    return 0;
}