#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int n_nodes;
    vector<vector<int>> adj;
};

void dfs(Graph g, int u, vector<bool> &visited) {
    visited[u] = true;
    for (int v : g.adj[u]) {
        if (!visited[v]) {
            dfs(g, v, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    Graph g;
    g.n_nodes = n;
    g.adj.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x) {
                g.adj[i].push_back(j);
                g.adj[j].push_back(i);
            }
        }
    }

    int count = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(g, i, visited);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
