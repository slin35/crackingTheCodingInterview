#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* 0 the entire column and row if an element is 0 
 * O(1) space
*/
void zeroMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
        int cols = matrix[0].size();
        bool colZero = false;
        bool rowZero = false;
        
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                colZero = true;
                break;
            }
        }
        
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                rowZero = true;
                break;
            }
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
               if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (colZero) {
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
        
        if (rowZero) {
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
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
    vector<vector<int>> matrix{ {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<vector<int>> answer{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
    zeroMatrix(matrix);
    assert(matrix == answer);
    return 0;
}       
