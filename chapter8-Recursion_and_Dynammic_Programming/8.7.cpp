#include <iostream>

using namespace std;

/* permutation without dups */
void getPermutation(string prefix, string rest) {
    int n = rest.size();
    
    if (n == 0) {
        cout << prefix << endl;
    }

    for (int i = 0; i < n; i++) {
        char cur = rest[i];
        string before = rest.substr(0, i);
        string after = rest.substr(i + 1);

        getPermutation(prefix + cur, before + after);
    }


}

int main() {
    getPermutation("", "abcd");
    return 0;
}
