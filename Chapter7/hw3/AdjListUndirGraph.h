#include <iostream>
#include <cstring>

using namespace std;

class Graph {
private:
    struct Edge {
        int v;
        int w;
        int next;
        Edge() : v(0), w(0), next(-1) {}
        Edge(int v, int w, int next) : v(v), w(w), next(next) {}
    };
    Edge* edges;
    int* head;
    int idx;
    int num_vertices;
    int num_edges;

public:
    Graph(int n, int m) : num_vertices(n), num_edges(m) {
        edges = new Edge[num_edges];
        head = new int[num_vertices];
        idx = 0;
        memset(head, -1, sizeof(int) * num_vertices);
    }

    ~Graph() {
        delete[] edges;
        delete[] head;
    }

    void add_edge(int u, int v, int w) {
        edges[idx] = Edge(v, w, head[u]);
        head[u] = idx++;
        edges[idx] = Edge(u, w, head[v]);
        head[v] = idx++;
    }

    void print_graph() {
        for (int u = 0; u < num_vertices; u++) {
            cout << "Vertex " << u << ": ";
            for (int i = head[u]; i != -1; i = edges[i].next) {
                cout << edges[i].v << "(" << edges[i].w << ") ";
            }
            cout << endl;
        }
    }
};
