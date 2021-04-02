#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isEqual(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b; 
}

/* group anagrams:
 * sort an array of strings so that all anagramsm are next to each other
*/
void groupAnagrams(vector<string>& array) {
    sort(array.begin(), array.end(), isEqual);
}


int main() {
    string a = "silent";
    string b = "listen";
    vector<string> array{"apple", "silent", "leppa", "listen", "abcdeddsdsds"};

    groupAnagrams(array);
    for (auto ele : array)
        cout << ele << " ";
    cout << endl;

    return 0;
}