#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/* triple steps:
 * a child is running up a staircase with n steps amd can hop either 1, 2, 3 steps at a time.
 * find how many possible ways the child can run up the stairs
*/

/* solution: recursion
 * to get to n steps:
 *      go (n - 1) steps, and hop 1
 *      go (n - 2) steps, and hop 2
 *      go (n - 3) steps, and hop 3
 * add them together
 * base case: n = 1 -> 1, n = 2 -> 2, n = 3 -> 4
*/
int countSteps(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    return countSteps(n - 3) + countSteps(n - 2) + countSteps(n - 1);
}

/* solution: dp */
int countSteps2(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2]  = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    assert(countSteps(1) == 1);
    assert(countSteps(2) == 2);
    assert(countSteps(3) == 4);

    assert(countSteps(4) == countSteps2(4));
    assert(countSteps(15) == countSteps2(15));
    return 0;
}