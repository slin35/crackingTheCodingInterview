#include <iostream>

using namespace std;

/* pairwise swap: swap odd and even bits as few instructions as possible 
 * 0xaa is mask for odd bits, shift them to the right
 * 0x55 is mask for even bits, shift them to the left
 * merge the two
*/
int swapOddEvenBits(int x) {
    return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}

int main() {

    return 0;
}