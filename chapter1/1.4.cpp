#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

/* check if the string is a permutation of palindrome */
bool isPalindromePer(string s) {
    bitset<26> table;

    for (char c : s) {
        if (table[c - 'a'] == 0)
            table.set(c - 'a');
        else 
            table.reset(c - 'a');
    }

    /* note: trick to check if there's only 1 bit set to 1 
     * ((x - 1) & x) == 0
    */
    return (table.to_ulong() & (table.to_ulong() - 1)) == 0;  // equilavent to table.count() <= 1

}

int main() {
    cout << isPalindromePer("aba") << endl;
    cout << isPalindromePer("hello") << endl;
    cout << isPalindromePer("abba") << endl;
    return 0;
}