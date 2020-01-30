#include <iostream>
#include <vector>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
int main() {
    int N;
    cin >> N;

    int floor1 = 0, floor2, ans = 0;
    while(N--) {
        cin >> floor2;
        if(floor2 > floor1)
            ans += (floor2 - floor1) * 6 + 5;
        else /*if(floor2 < floor1)*/
            ans += (floor1 - floor2) * 4 + 5;
        floor1 = floor2;
    }
    cout << ans;
    return 0;
}