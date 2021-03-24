#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/* check if one is the permutation of the other 
 * or use table of counts
 * is permutation case sensitive
 * ascii or unicode string
*/
bool checkPermutation(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main() {
    cout << checkPermutation("aaa", "bbb") << endl;
    cout << checkPermutation("abc", "cba") << endl;
    return 0;
}