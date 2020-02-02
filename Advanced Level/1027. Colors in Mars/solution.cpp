#include <iostream>
using namespace std;

void helper() {
    static char table[] = "0123456789ABC";
    int n;
    cin >> n;
    cout << table[n / 13] << table[n % 13];
}
int main() {
    cout << '#';
    helper();
    helper();
    helper();
    return 0;
}