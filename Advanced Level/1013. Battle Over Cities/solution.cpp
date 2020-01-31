#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

void dfs(const vector<vector<int>> &trees, vector<bool> &visit, int cur_city, int lost_city) {
    if(visit[cur_city] || cur_city == lost_city)
        return;
    visit[cur_city] = true;
    for(auto city:trees[cur_city])
        dfs(trees, visit, city, lost_city);
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    //build the trees, trees[i] represent the cities connected the city i
    vector<vector<int>> trees(n+1);//cities are numbered from 1 to n
    for(int i = 0;i < m;++i) {
        int city1, city2;
        cin >> city1 >> city2;
        trees[city1].push_back(city2); 
        trees[city2].push_back(city1);
    }
    //inquire
    for(int i = 0;i < k;++i) {
        int lost_city;
        cin >> lost_city;

        vector<bool> visit(trees.size(), false);
        visit[0] = visit[lost_city] = true;
        //select the city to exec dfs
        int cnt = 0;//number of tree in trees
        for(int cur_city = 1;cur_city <= n;++cur_city)
            if(visit[cur_city] == false) {
                dfs(trees, visit, cur_city, lost_city);
                ++cnt;
            }

        cout << (cnt-1) << endl;
    }
    return 0;
}