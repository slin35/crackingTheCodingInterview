#include <iostream>
#include <cassert>


using namespace std;

/* conversion: determine the number of bits needed to convert A to B */
int convert(int A, int B) {
    int tmp = A ^ B;
    int cnt = 0;

    while (tmp != 0) {
        if ((tmp & 1) == 1)
            cnt++;
        tmp >>= 1;
    }

    return cnt;
}

int main() {
    assert(convert(29, 15) == 2);
    return 0;
}