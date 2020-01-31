#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Info {
    //A C M E
    int id, best_rank_idx, scores[4], ranks[4];
};
int main() {
    //input the scores
    int n, m;
    cin >> n >> m;
    vector<Info> v(n);
    for(int i = 0;i < n; ++i) {
        cin >> v[i].id;
        //C M E
        cin >> v[i].scores[1] >> v[i].scores[2] >> v[i].scores[3];
        // A
        v[i].scores[0] = (v[i].scores[1] + v[i].scores[2] + v[i].scores[3]) / 3.0 + 0.5;
    }
    //sort the scores and get the ranks
    for(int i = 0;i < 4;++i) {
        //sort
        sort(
            v.begin(),
            v.end(),
            [i](const Info&x, const Info &y) {
                return x.scores[i] > y.scores[i];
            }
        );
        //get the rank, if there are two student get the same rank i, there is no rank i+1
        v[0].ranks[i] = 1;
        for(int j = 1;j < n;++j)
            v[j].ranks[i] = v[j].scores[i] == v[j-1].scores[i] ? v[j-1].ranks[i] : j + 1;
    }
    //get the best rank and build the mapping of id to index
    map<int,int> id2idx;
    for(int i = 0;i < n; ++i) {
        //build the mapping
        id2idx[v[i].id] = i;
        //get the best rank
        int &idx = v[i].best_rank_idx;
        for(int j = 1;j < 4;++j)
            if(v[i].ranks[j] < v[i].ranks[idx])
                idx = j;
    }
    //inquire
    int id;
    char table[] = {'A', 'C', 'M', 'E'}; 
    for(int i = 0; i < m; ++i) {
        cin >> id;
        auto iter = id2idx.find(id);
        if(iter != id2idx.end()) {
            auto & info = v[iter->second];
            cout << info.ranks[info.best_rank_idx] << ' ' << table[info.best_rank_idx] << endl;
        } else
            cout << "N/A\n";
    }
    return 0;
}