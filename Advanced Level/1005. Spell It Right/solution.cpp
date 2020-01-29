#include <string>
#include <iostream>
#include <vector>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

int main() {
    //input
    string num;
    cin >> num;
    int sum = 0;
    for(auto digit: num) {
        sum += digit - '0';
    }
    //ouput
    vector<string> table = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    bool flag = false;
    for(auto digit: to_string(sum)) {
        if(flag) {
            cout << ' ';
        }
        flag = true;
        cout << table[digit-'0'];
    }
    return 0;
}