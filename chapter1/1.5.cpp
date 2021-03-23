#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

/* check if two strings are 1 or 1 edit distance away from each other */
bool oneArray(string s1, string s2) {
    bool found = false;

    for (int i = 0, j = 0; i < s1.size() && j < s2.size();) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        }
        else {
            if (found) return false;
            found = true;
            
            if (s1.size() == s2.size()) {
                i++;
                j++;
                
            }
            else if (s1.size() < s2.size()) {
                j++;
            }
            else {
                i++;
            }
        }
    }

    return true;
}

int main() {

    assert(oneArray("pale", "ple") == true);
    assert(oneArray("pales", "pale") == true);
    assert(oneArray("pale", "bale") == true);
    assert(oneArray("pale", "bae") == false);

    return 0;
}