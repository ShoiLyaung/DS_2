#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(vector<vector<int>>& adj_list, int start, int length, unordered_set<int>& visited) {
    visited.insert(start);
    if (length == 1) {  // 找到了长度为A的路径
        return true;
    }
    for (int neighbor : adj_list[start]) {
        if (visited.find(neighbor) == visited.end()) {  // 遍历未访问过的邻居节点
            if (dfs(adj_list, neighbor, length - 1, visited)) {
                return true;
            }
        }
    }
    visited.erase(start);  // 回溯时要将节点标记为未访问
    return false;
}

bool has_simple_path(vector<vector<int>>& adj_list, int start, int length) {
    unordered_set<int> visited;
    return dfs(adj_list, start, length, visited);
}

int main() {
    int n, m, a;
    cin >> n >> m >> a;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool exists = false;
    for (int i = 0; i < n; i++) {
        exists |= has_simple_path(adj_list, i, a);
    }
    cout << (exists ? "YES" : "NO") << endl;
    return 0;
}
