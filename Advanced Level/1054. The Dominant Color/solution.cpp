#include <map>
#include <iostream>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
int main() {
    map<int,int> val2cnt;
    int m, n, val;
    cin >> m >> n;
    int half = m * n / 2;
    while(m--)
        for(int i = 0; i < n; ++i) {
            cin >> val;
            if( ++val2cnt[val] > half) {
                cout << val;
                return 0;
            }
        }
    return 0;
}