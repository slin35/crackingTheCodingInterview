#include <iostream>
#include <algorithm>
#include <cassert>
#include <bitset>

using namespace std;

/* flip bit to win: 
 * given an integer, you can flip 1 bit from 0 to 1, find the length of the longest 1s possible
 * solution:
 *  keeping track of current sequences of 1s and previous sequences of 1s
 *  when seeing a 0, update the sequences count:
 *      if the next bit of the current 0 is 0, the previous sequences cnt set to 0 (cant merge)
 *      if the next bit of the current 0 is 1, can be merge, set previous sequences cnt to current cnt (also update current)
*/
int flipOneBit(int num) {
    if (~num == 0)
        return sizeof(num) * 8;

    int cur = 0, prev = 0, maxLen = 1; // at least 1;

    while (num != 0) {
        if ((num & 1) == 1) { // if the 0th bit is 1, add 1 to cur
            cur++;
        }
        else {
            if ((num & 2) == 0) { // if the 1th bit is 0, cannot merge cur and prev, update both
                prev = 0;
            }
            else {
                prev = cur;
            }

            cur = 0;
        }

        maxLen = max(prev + cur + 1, maxLen);
        num >>= 1;
    }

    cout << maxLen << endl;
    return maxLen;

}


int main() {
    assert(flipOneBit(1775) == 8);
    return 0;
}