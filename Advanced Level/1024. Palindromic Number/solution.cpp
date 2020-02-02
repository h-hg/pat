#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
estimation:
    n = 1e10, k = 100
    n * (2^k) > LLONG_MAX
conclusion:
    big integer
*/
void add_reverse(string &num) {
    string num2(num.rbegin(), num.rend());
    int r = 0;
    for(int i = 0, n = num.size(); i < n; ++i) {
        int sum = num[i] + num2[i] + r - '0' - '0';
        num[i] = sum % 10 + '0';
        r = sum / 10;
    }
    if(r)
        num.push_back(r + '0');
    reverse(num.begin(), num.end());
}
bool check(const string &strn) {
    for(int l = 0, r = strn.size() - 1; l < r;)
        if(strn[l++] != strn[r--])
            return false;
    return true;
}
int main() {
    string n;
    int k;
    cin >> n >> k;
    int cnt = 0;
    for(;cnt < k && !check(n); ++cnt)
        add_reverse(n);
    cout << n << endl << (cnt > k ? k : cnt);
    return 0;
}