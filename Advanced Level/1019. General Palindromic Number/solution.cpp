#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> base2(long long n, long long b) {
    vector<int> ret;
    do {
        ret.push_back(n % b);
        n /= b;
    }while(n);
    reverse(ret.begin(), ret.end());
    return ret;
}
bool check(const vector<int> &v) {
    for(int l = 0, r = v.size() - 1; l < r;)
        if(v[l++] != v[r--])
            return false;
    return true;
}
int main() {
    long long n, b;
    cin >> n >> b;
    auto v = base2(n, b);
    cout << (check(v) ? "Yes\n" : "No\n");
    cout << v[0];
    for(int i = 1;i < v.size();++i)
        cout << ' ' << v[i];

    return 0;
}