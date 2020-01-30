#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//return reversed number base 10
int get_reversed_num_base10(int n, int base) {
    //convert to the number system `base` and reverse the number
    string num_base;
    do {
        num_base.push_back(n % base + '0');
        n /= base;
    }while(n);
    //convert to the number system 10
    return stoi(num_base, nullptr, base);
}
bool isPrime(int n) {
    if( n <= 1 || (n != 2 && (n & 1 == 0)) )
        return false;
    int maxn = sqrt(n);
    for(int i = 2;i <= maxn; ++i)
        if(n % i == 0)
            return false;
    return true;
}
int main() {
    int N, D;
    while(cin >> N, N > 0) {
        cin >> D;
        if(isPrime(N) && isPrime(get_reversed_num_base10(N, D)))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}