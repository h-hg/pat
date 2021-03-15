#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string num1;
    cin >> num1;
    auto num2 = num1;
    int r = 0;
    for(auto riter = num2.rbegin(); riter != num2.rend(); ++riter) {
        int val = ((*riter-'0') << 1) + r;
        *riter = val % 10 + '0';
        r = val / 10;
    }
    if(r != 0)
        cout << "No\n" << r << num2;
    else {
        auto tmp = num2;
        sort(num1.begin(), num1.end());
        sort(num2.begin(), num2.end());
        if(num1 == num2)
            cout << "Yes\n" << tmp;
        else
            cout << "No\n" << tmp;
    }
    return 0;
}