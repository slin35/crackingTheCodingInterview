#include <iostream>

using namespace std;

/* next number: 
 * given a positive integer, print the next smallest and largest number that have the same number of 1 bits
*/

/*  solution:
 *      1. flip the rightmost non-trailing 0 to 1, mark the position as p
 *      2. count the number of 1s on the right of p, clear bits after p, mark as n
 *      3. add (n - 1) 1s back from the rightmost side back to the original number
*/
int getNext(int num) {
    int tmp = num;
    int c0 = 0, c1 = 0;

    while ((tmp & 1) == 0 && tmp != 0) {
        tmp >>= 1;
        c0++;
    }

    while ((tmp & 1) == 1 && tmp != 0) {
        tmp >>= 1;
        c1++;
    }

    // error checking
    if (c0 + c1 == 32 || c0 + c1 == 0) {
        throw "no such number";
    }

    int p = c0 + c1;
    num |= (1 << p);          // set the rightmost non-trailing 0 to 1
    num &= ~((1 << p) - 1);     // clear all bits after p
    num |= (1 << (c1 - 1)) - 1;     // add (n - 1) 1s back

    return num;
}

/* solution:
 *      1. flip the rightmost non-trailing 1 to 0, mark the position as p
 *      2. count the nummebr of 1s on the right of p, clear bits after p, mark as n
 *      3. add (n + 1) 1s back from the leftmost side of p back to the original number
*/
int getPrev(int num) {
    int tmp = num;
    int c0 = 0, c1 = 0;

    while ((tmp & 1) == 0 && tmp != 0) {
        tmp >>= 1;
        c1++;
    }

    while ((tmp & 1) == 1 && tmp != 0) {
        tmp >>= 1;
        c0++;
    }

    int p = c0 + c1;
    num &= ((~0) << (p + 1));
    num |= ((1 << (c1 + 1)) - 1) << (c0 - 1);

    return num;
}

int main() {
    
    return 0;
}