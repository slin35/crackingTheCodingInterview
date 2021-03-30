#include <iostream>
#include <map>

using namespace std;

/* string permutation with duplicates */
void getPermuation(string prefix, int cnt, map<char, int>& mymap) {
    if (cnt == 0)
        cout << prefix << endl;

    for (auto pair : mymap) {
        if (pair.second != 0) {
            char cur = pair.first;
            mymap[cur] -= 1;
            getPermuation(prefix  + cur, cnt - 1, mymap);
            mymap[cur] += 1;
        }
    }
}

int main() {
    map<char, int> mymap{{'a', 5}};
    map<char, int> mymap2{{'a', 2}, {'b', 1}, {'c', 1}};
    getPermuation("", 5, mymap);
    getPermuation("", 4, mymap2);
    return 0;
}