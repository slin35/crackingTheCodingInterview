#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/* sparse search */
int sparseSearch(vector<string> array, string target) {
    int start = 0, end = array.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (array[mid] == "") {  // if its empty string
            int tmp = mid;
            while (tmp > start && array[tmp] == "") {
                tmp--;
            }
            if (array[tmp] == "") {
                tmp = mid;
                while (tmp < end && array[tmp] == "") {
                    tmp++;
                }
            }
            mid = tmp;
        }        

        if (array[mid] > target) {
            end = mid - 1;
        }
        else if (array[mid] == target) {
            return mid;
        }
        else if (array[mid] < target) {
            start = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<string> array{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    vector<string> array2{"", "", "", "", "", "no", "yes"};

    assert(sparseSearch(array, "ball") == 4);
    assert(sparseSearch(array2, "yes") == 6);
    assert(sparseSearch(array2, "no") == 5);
    
    return 0;
}