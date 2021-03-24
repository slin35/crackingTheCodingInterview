#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

/* check if one string is the rotation of the other */
bool rotateString(string A, string B) {
    if (A.length() != B.length())
        return false;

    string combo = A + A;

    if (combo.find(B) != string::npos)
        return true;
    return false;
}

int main() {
    assert(rotateString("abcde","cdeab") == true);
    assert(rotateString("aa", "a") == false);
    assert(rotateString("abcde", "abced") == false);
    return 0;
}