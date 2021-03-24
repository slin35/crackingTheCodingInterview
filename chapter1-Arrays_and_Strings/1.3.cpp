#include <iostream>
#include <cstring>

using namespace std;

/* replace space with "%20" */
void URLify(string& url) {
    int idx = url.size() - 1;
    int i = idx;

    while (url[idx] == ' ') {idx--;}

    while (i > 0) {
        if (url[idx] == ' ') {
            url.replace(i - 2, 3, "%20");
            i -= 3;
        }
        else {
            url[i] = url[idx];
            i--;
        }
        idx--;
    }
}

int main() {
    string url = "Mr John Smith    ";
    URLify(url);
    cout << url << endl;
    return 0;
}