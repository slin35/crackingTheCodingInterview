/* N-Queen problem (leetcode 51) */
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        cols = vector<bool>(n, true);
        dig = vector<bool>(2*n - 1, true);
        dig2 = vector<bool>(2*n - 1, true);
        
        
        traceBack(0, n);
        
        return result;
    }
    
    void traceBack(int row, int n) {
        if (row == n) {
            result.push_back(sol);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, n)) {
                placeQueen(row, i, n);
                sol.push_back(genString(i, n));
                
                
                traceBack(row + 1, n);
            
                removeQueen(row, i, n);
                sol.pop_back();
            }
        }
    }
    
    bool isValid(int row, int col, int n) {
        return cols[col] && dig[row + col] && dig2[row - col + n - 1];
    }
    
    void placeQueen(int row, int col, int n) {
        cols[col] = false;
        dig[col + row] = false;
        dig2[row - col + n - 1] = false;
    }
    
    void removeQueen(int row, int col, int n) {
        cols[col] = true;
        dig[col + row] = true;
        dig2[row - col + n - 1] = true;
    }
    
    string genString(int idx, int n) {
        string res = "";
        for (int i = 0; i < n; i++) {
            if (i == idx)
                res += 'Q';
            else
                res += '.';
        }
        return res;
    }
    
    private:
        vector<vector<string>> result;
        vector<bool> cols;
        vector<bool> dig;
        vector<bool> dig2;
        vector<string> sol;


};