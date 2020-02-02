#include <iostream>
#include <string>
using namespace std;
/*
    n1 = 4, n2 = 3, size = 12
    1  2  3
    4  5  6
    7  8  9
    10 11 12

*/
int main() {
    string str;
    cin >> str;
    int n = str.size(), n1 = (n + 2) / 3, n2 = n - 2 * n1 + 2, size = n1 * n2;
    int idx1 = 0, idx2 = n1, idx3 = n - 1;
    for(int i = 1; i <= size; ++i) {
        auto tmp = i % n2;
        if(tmp == 1)
            cout << str[idx1++];
        else if(tmp == 0)
            cout << str[idx3--];
        else if(i / n2 == n1 - 1)
            cout << str[idx2++];
        else
            cout << ' ';
        if(i % n2 == 0)
            cout << endl;
    }
    return 0;
}