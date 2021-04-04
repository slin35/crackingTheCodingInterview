#include <iostream>
#include <vector>
#include <bitset>


using namespace std;

/* find duplicates:
 *      numbers from 1 to N, N is at most 32000. 4 KB memory available. Print all dups.
 * 
 * thoughts: 4 KB. 4 * 1024 bytes = 8 * 4 * 1024 bits = 8 * 4 * 2^10 = 2^15.
 * 32000 bitset can be created
*/
void printDuplicates(vector<int> array) {
    bitset<32000> s;
    for (int i = 0; i < array.size(); i++) {
        if (s[array[i] - 1]) {
            cout << array[i] << endl;
        }
        else {
            s.set(array[i] - 1);
        }
    }
}

int main() {


    return 0;
}