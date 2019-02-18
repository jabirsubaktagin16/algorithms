#include <bits/stdc++.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

vector<int> adj[105];
int color[105];

void DFS(int u) {
    color[u] = GREY;

    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i) {
        int v = adj[u][i];

        if(color[v] == WHITE)
            DFS(v);
    }

    color[u] = BLACK;
    cout << u <<" ";
}

int main() {
    cout << "Enter the number of Nodes: ";
    int V;
    cin >> V;

    cout << "Enter the number of edges: ";
    int E;
    cin >> E;

    cout << "Enter the edges:" << endl;
    for(int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << endl;
    cout << "DFS traversal nodes are: " << endl;
    for(int i = 1; i <= V; ++i) {
        if(color[i] == WHITE) {
            DFS(i);
        }
    }
}
