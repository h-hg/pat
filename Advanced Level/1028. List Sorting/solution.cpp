#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/* struct Stu{
    string id, name, score;
    Stu(const string &_id, const string _name, const string &_score):id(_id), name(_name), score(_score){}
}; */
static auto _= []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
using Stu = vector<string>;
int main() {
    //freopen("in.txt", "r", stdin);
    int n,c;
    cin >> n >> c;
    string id, name, score;
    vector<Stu> stus;
    stus.reserve(n);
    while(n--) {
        cin >> id >> name >> score;
        stus.push_back({id, name, score});
    }
    c -= 1;
    if(c == 0)
        sort(stus.begin(), stus.end(), [c](const Stu &x, const Stu &y){return x[c] < y[c];});
    else
        sort(stus.begin(), stus.end(), [c](const Stu &x, const Stu &y){return x[c] == y[c] ? x[0] < y[0] : x[c] < y[c];});
    for(auto &stu : stus) {
        cout << stu[0] << ' ' << stu[1] << ' ' << stu[2] << endl;
    }
    return 0;
}