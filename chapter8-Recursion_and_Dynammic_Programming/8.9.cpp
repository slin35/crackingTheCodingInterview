#include <iostream>
#include <vector>

using namespace std;

/* parens: print all valid combinations of n pairs of parentheses */
void getParens(int open, int close, int n, string cur) {
    if (cur.size() == 2 * n) {
        cout << cur << endl;
        return;
    }

    if (open < n) {
        getParens(open + 1, close, n, cur + "(");
    }

    if (close < open) {
        getParens(open, close + 1, n, cur + ")");
    }

}


int main() {

    getParens(0, 0, 5, "");

    return 0;
}