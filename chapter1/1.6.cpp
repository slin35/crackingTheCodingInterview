#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/* string compression with O(1) space */
int compress(string& s) {
    if (s.size() == 1)
        return 1;

    int res = 0, start = 0, end = 0;

    while (end < s.size()) {

        while (end < s.size() && s[start] == s[end]) { end++; }

        s[res++] = s[start];

        if (end - start > 1) {
            string cnt = to_string(end - start);
            for (char c : cnt) {
                s[res++] = c;
            }
        }

        start = end;
    }

    return res;
}

int main() {
    string s = "aabcccccaaa";
    assert(s.substr(0, compress(s)) == "a2bc5a3");
    return 0;
}