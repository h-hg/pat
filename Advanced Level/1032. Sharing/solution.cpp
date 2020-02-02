#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<int> l(1e5+1, -1);
int main() {
    int addr1, addr2, n;
    cin >> addr1 >> addr2 >> n;
    while(n--) {
        int id, next;
        char data;
        cin >> id >> data >> next;
        l[id] = next;
    }
    set<int> addrs1;
    while(addr1 != -1 ) {
        addrs1.insert(addr1);
        addr1 = l[addr1];
    }
    
    while(addr2 != -1) {
        if(addrs1.find(addr2) != addrs1.end()) {
            cout << setw(5) << setfill('0') <<addr2;
            return 0;
        }
        addr2 = l[addr2];
    }
    cout << "-1";
    return 0;
}