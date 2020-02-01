#include <iostream>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
void query(map<string, set<int> > &table, const string &str) {
    auto iter = table.find(str);
    if(iter != table.end()) {
        auto &ids = iter->second;
        for(auto id:ids)
            cout << setw(7) << setfill('0') << id << endl;
    } else
        cout << "Not Found\n";
}
int main() {
    int n;
    cin >> n;
    int id;
    map<string, set<int> > title2ids, auth2ids, key2ids, pub2ids, year2ids;
    string title, auth, key, pub, year;
    for(int i = 0; i < n; i++) {
        (cin >> id).ignore();
        getline(cin, title);
        title2ids[title].insert(id);
        getline(cin, auth);
        auth2ids[auth].insert(id);
        while(cin >> key) {
            key2ids[key].insert(id);
            if('\n' == cin.get())
                break;
        }
        getline(cin, pub);
        pub2ids[pub].insert(id);
        getline(cin, year);
        year2ids[year].insert(id);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int opt;
        (cin >> opt).ignore().ignore();
        string str;
        getline(cin, str);
        cout << opt << ": " << str << "\n";
        switch (opt)
        {
        case 1:
            query(title2ids, str);
            break;
        case 2:
            query(auth2ids, str);
            break;
        case 3:
            query(key2ids, str);
            break;
        case 4:
            query(pub2ids,str);
            break;
        case 5:
            query(year2ids, str);
            break;
        }
    }
    return 0;
}