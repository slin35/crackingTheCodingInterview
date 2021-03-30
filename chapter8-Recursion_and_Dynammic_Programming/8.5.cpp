#include <iostream>
#include <cassert>

using namespace std;

/* recursive multiply: recursively multiply two positive integers without using * operator */
int multiply(int x, int y) {
    int s = x > y ? y : x;
    int b = x > y ? x : y;

    if (s == 0)
        return 0;
    if (s == 1) {
        return b;
    }

    int sn = s >> 1;
    int half = multiply(sn, b);

    if (s % 2 == 0)
        return half + half;
    else 
        return half + half + b;
}

int main() {
    assert(multiply(5, 3) == 15);
    assert(multiply(0, 16) == 0);
    assert(multiply(8, 1) == 8);
    assert(multiply(81, 99) == 8019);

    return 0;
}