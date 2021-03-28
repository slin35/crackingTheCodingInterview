#include <iostream>

using namespace std;


/* binary to string: 
 * given a real number (double) between 0 and 1, print out the binary representation 
 * print "ERROR" if exceeds 32 characters
 *
 * solution:
 *  2 * n to shift the fractional sum
 *  if greater than 1, there's a 1, else its a 0
*/
void binaryString(double num) {
    string res;

    while (num > 0) {
        if (res.size() >= 32) {
            cout << "ERROR" << endl;
            return;
        }

        double r = num * 2;
        if ( r >= 1) {
            res += "1";
            num = r - 1;
        }
        else {
            res += "0";
            num = r;
        }

    }

    cout << res << endl;
}


int main() {
    binaryString(0.75);
    return 0;
}