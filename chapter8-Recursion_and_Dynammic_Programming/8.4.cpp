#include <iostream>
#include <vector>

using namespace std;

/* return power set of the set */
void getSubset(string str, int index = -1, string cur = "") {
    if (index == str.length())
        return;

    cout << cur << endl;
    int n = str.size();
    for (int i = index + 1; i < str.size(); i++) {
        cur += str[i];
        getSubset(str, i, cur);
        cur.erase(cur.size() - 1);
    }

    return;
}

int main() {
    getSubset("1234");

    return 0;
}