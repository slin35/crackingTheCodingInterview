#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/* sorted matrix search: gieven an M x N matrix in which each row and col is sorted in ascending order */
void search(vector<vector<int>> matrix, int val) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int i = 0, j = cols - 1;

    while (i < rows && j >= 0) {
        if (matrix[i][j] == val) {
            printf("found i: %d, j: %d", i, j);
            return;
        }
        else if (matrix[i][j] < val) {
            i++;
        }
        else {
            j--;
        }
    }

    cout << "not found" << endl;
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
    vector<vector<int>> matrix{{15, 20, 40, 85}, {20, 35, 80, 95}, {30, 55, 95, 105}, {40, 80, 100, 120}};

    search(matrix, 80);
    search(matrix, 101);

    return 0;
}