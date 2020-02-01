#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
bool modify(string &pwd) {
    static map<char,char> table = {{'1','@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
    bool ret = false;
    for(auto &c:pwd) {
        auto iter = table.find(c);
        if(iter != table.end()) {
            c = iter->second;
            ret = true;
        }
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0;i < n;++i) {
        string name, pwd;
        cin >> name >> pwd;
        if(modify(pwd))
            v.push_back(name + " " + pwd);
    }
    if(v.size() != 0) {
        cout << v.size() << endl;
        for(auto & val:v)
            cout << val << endl;
    } else if(n == 1){
        cout << "There is 1 account and no account is modified";
    } else {
        cout << "There are " << n << " accounts and no account is modified";
    }
    return 0;
}