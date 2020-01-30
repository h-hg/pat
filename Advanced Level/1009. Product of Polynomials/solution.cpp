#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
map<int, double> input_poly() {
    int k;
    map<int, double> poly;
    cin >> k;
    while(k--) {
        int exp;
        double coeff;
        cin >> exp >> coeff;
        poly[exp] = coeff;
    }
    return poly;
}
void output_poly(map<int, double> &poly) {
    int n = 0;
    for(auto &p:poly)
        if(p.second != 0.0)
            ++n;
    cout << n;
    for(auto riter = poly.rbegin(); riter != poly.rend(); ++riter)
        if(riter->second != 0.0)
            cout << ' ' << (riter->first) << ' ' << setiosflags(ios::fixed) << setprecision(1) << (riter->second);
    
}
int main() {
    //input
    auto poly1 = input_poly(), poly2 = input_poly();
    //multiply
    map<int, double> product;
    for(auto &p1:poly1)
        for(auto &p2:poly2)
            product[p1.first + p2.first] += p1.second * p2.second;
    //output
    output_poly(product);
    return 0;
}