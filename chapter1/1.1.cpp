#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

#define  NUM 256

/* determine if a string has all unique characters 
 * without direct mapping, could prob solve with sorting and check two of the same neighbors
*/
bool isUnique(string s) {
    bitset<256> table;      // can be replaced with an int if conditions allow

    for (char c : s) {
        if (table[c - '\0'])
            return false;
        else 
            table.set( c- '\0');
    }

    return true;
}

int main() {
    cout << isUnique("abcde") << endl;
    cout << isUnique("abcdde") << endl;
    return 0;
}