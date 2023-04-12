#include "AdjListUndirGraph.h"

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    g.print_graph();
    return 0;
}
