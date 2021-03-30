#include <iostream>
#include <vector>


using namespace std;

/* find magic index in sorted array with distinct elements. Ex: A[i] = i as magic index 
 * if the elements in the array are not distinct, 
 *  search the other size as well but look for the min and max if the index and current value
 *  util the situation silimar to the original problem
*/
int findMagicIndex(vector<int> array, int start, int end) {
    if (start > end)
        return -1;
    
    int mid = start + (end - start) / 2;
    if (array[mid] == mid)
        return mid;
    else if (array[mid] < mid) {
        return findMagicIndex(array, mid + 1, end);
    }
    return findMagicIndex(array, start, mid - 1);
}


int main() {
    vector<int> array{-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};

    cout << findMagicIndex(array, 0, array.size()) << endl;

    return 0;
}