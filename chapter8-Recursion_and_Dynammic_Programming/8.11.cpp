#include <iostream>
#include <vector>

using namespace std;

/* coins: 
 * there are infinite number of quarters (25 cents), dimes (10 cents), nickles (5 cents), and pennies (1 cents),
 * count number of ways (unique) representing n cents
*/
int count(int n, vector<int> denoms, int cur) {
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int res = 0;

    for (int i = cur; i < denoms.size(); i++) {
        res += count(n - denoms[i], denoms, i);
    }

    return res;
}

int main() {
    vector<int> denoms{1, 5, 10, 25};
    cout << count(15, denoms, 0) << endl;

    return 0;
}