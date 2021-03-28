#include <iostream>
#include <cstdint>
#include <cassert>
#include <bitset>

using namespace std;

/* insertion: insert number M into N such that M starts and ends at indicated positions in N 
 * solution:
 * clear bits from start to end in N and toggle the bit to the corresponding value in M as it goes
*/
int32_t insertion(int32_t N, int32_t M, int start, int end) {
    int cnt = start;
    while (cnt <= end) {
        int mask = ~(1 << cnt);
        int val = (M & (1 << (cnt - start))) == 0 ? 0 : 1;
        N = (N & mask) | (val << cnt);
        cnt++;
    }
    return N;
}

/* solution 2:
 * clear bits in N first, then merge in shifted M
*/
int32_t insertion2(int32_t N, int32_t M, int start, int end) {
    int32_t left = (~0) << (end + 1);
    int32_t right = (1 << start) - 1;
    int mask = left | right;

    return (N & mask) | (M << start);
}

int main() {
    assert(insertion2(0b10000000000, 0b10011, 2, 6) == 0b10001001100);
    return 0;
}