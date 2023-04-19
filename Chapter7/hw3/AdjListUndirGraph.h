#include <iostream>
#include <cstring>

using namespace std;

struct Edge {
    int u, v;
    int nextu, nextv;
    int weight;
    Edge() {}
    Edge(int u, int v, int nextu, int nextv, int weight) : u(u), v(v), nextu(nextu), nextv(nextv), weight(weight) {}
};

class Graph {
private:
    Edge* edges;
    int* head;
    int idx;
    int num_vertices;
    int num_edges;

public:
    Graph(int n, int m) : num_vertices(n), num_edges(m) {
        edges = new Edge[2 * num_edges];
        head = new int[num_vertices];
        idx = 0;
        memset(head, -1, sizeof(int) * num_vertices);
    }

    ~Graph() {
        delete[] edges;
        delete[] head;
    }

    void add_edge(int u, int v, int weight) {
        edges[idx] = Edge(u, v, head[u], head[v], weight);
        head[u] = head[v] = idx++;
    }

    void print_graph() {
        for (int u = 0; u < num_vertices; u++) {
            cout << "Vertex " << u << ": ";
            for (int i = head[u]; i != -1; i = (u == edges[i].u ? edges[i].nextu : edges[i].nextv)) {
                int v = (u == edges[i].u ? edges[i].v : edges[i].u);
                cout << "(" << v << ", " << edges[i].weight << ") ";
            }
            cout << endl;
        }
    }

    void DFS(int u, bool* visited) {
        visited[u] = true;
        cout << u << " ";
        for (int i = head[u]; i != -1; i = (u == edges[i].u ? edges[i].nextu : edges[i].nextv)) {
            int v = (u == edges[i].u ? edges[i].v : edges[i].u);
            if (!visited[v]) {
                DFS(v, visited);
            }
        }
    }
};
