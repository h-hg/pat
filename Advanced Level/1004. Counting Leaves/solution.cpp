#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
    //input
    int N, M;
    scanf("%d%d", &N, &M);
    vector<vector<int>> tree(100);
    for(int i = 0;i < M;++i) {
        int id, k;
        scanf("%d%d", &id, &k);
        auto &node = tree[id];
        node.reserve(k);
        for(int j = 0; j < k; ++j) {
            scanf("%d",&id);
            node.push_back(id);
        }
    }
    //bfs
    queue<vector<int>*> q;
    q.push(&tree[1]);
    bool flag = false;
    while(q.size()) {
        int cnt = 0;//number of family members who hava no child for every seniority level
        int n = q.size();
        for(int i = 0;i < n;++i) {
            auto &node = *q.front();
            q.pop();
            if(node.empty()) {
                ++cnt;
            }else {
                for(auto child_id:node) {
                    q.push(&tree[child_id]);
                }
            }
        }
        //output
        if(flag) {
            printf(" ");
        }
        flag = true;
        printf("%d", cnt);
    }
    return 0;
}