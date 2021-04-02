#include <iostream>

using namespace std;

/* sorted search, no size */
/* use elementAt(i) to find an index valid and less than the value */
/* then perform binary search */
int bSearch(int array[], int value, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] > value)
            end = mid - 1;
        else if (array[mid] < value)
            start = mid + 1;
        else 
            return mid;
    }
    return -1;
}

int main() {

    return 0;
}