#include <iostream>
#include <vector>

using namespace std;

/* sorted merge:
 * given 2 sorted array A and B, merge B into A as A is large enough to hold B
*/
void mergeSorted(vector<int>& A, vector<int>& B, int i, int j) {
    int n = A.size();

    for (int cur = n - 1; cur >= 0; cur--) {
        if (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[cur] = A[i];
                i--;
            }
            else {
                A[cur] = B[j];
                j--;
            }
        }
        else if (i >= 0) {
            A[cur] = A[i];
            i--;
        }
        else if (j >= 0) {
            A[cur] = B[j];
            j--;
        }

    }
}

int main() {
    vector<int> A{0, 2, 4, 6, 8, 10, 0, 0, 0, 0, 0};
    vector<int> B{1, 3, 5, 7, 9};

    mergeSorted(A, B, A.size() - B.size() - 1, B.size() - 1);

    for (auto ele : A)
        cout << ele << " ";
    cout << endl;

    return 0;
}