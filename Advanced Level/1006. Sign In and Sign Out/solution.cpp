#include <iostream>
#include <climits>
#include <string>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main() {
    int M;
    cin >> M;
    string id_in, id_out;
    int time_min = INT_MAX, time_max = INT_MIN;
    while(M--) {
        string id;
        int hh, mm, ss;
        char delim;
        cin >> id;
        cin >> hh >> delim >> mm >> delim >> ss;
        int time_in = hh * 3600 + mm * 60 + ss;
        cin >> hh >> delim >> mm >> delim >> ss;
        int time_out = hh * 3600 + mm * 60 + ss;
        if(time_in < time_min) {
            time_min = time_in;
            id_in = id;
        }
        if(time_out > time_max) {
            time_max = time_out;
            id_out = id;
        }
    }
    cout << id_in << ' ' << id_out;
    return 0;
}