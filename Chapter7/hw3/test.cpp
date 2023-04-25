#include "AdjListUndirGraph.h"

using namespace std;

int main() {
    Graph g(5, 6);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 1);
    g.add_edge(1, 2, 3);
    g.add_edge(2, 3, 4);
    g.add_edge(3, 4, 5);
    g.add_edge(4, 0, 6);

    g.print_graph();

    // cout << "DFS traversal: ";
    // g.DFS(0);
    // cout << endl;
    
    g.has_simple_path(11);
    cout << endl;

    return 0;
}
