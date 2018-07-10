#include<bits/stdc++.h>
#include<vector>
#define edge pair <int,int>
using namespace std;

int node;
class Graph{
private:
    vector<pair<int,edge> > G;
    vector<pair<int,edge> > T;
    int *parent;
public:
    Graph(int node);
    void AddWeightedEdge(int source, int dest, int weight);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int node){
    parent=new int[node];
    for(int i=0;i<node;i++)
        parent[i]=i;
    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int source,int dest,int weight){
        G.push_back(make_pair(weight,edge(source,dest)));
}
int Graph::find_set(int i){
    if (i==parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph::union_set(int u,int v){
    parent[u]=parent[v];
}
void Graph::kruskal() {
    int i, u1, v1;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++) {
        u1 = find_set(G[i].second.first);
        v1 = find_set(G[i].second.second);
        if (u1 != v1) {
            T.push_back(G[i]);
            union_set(u1, v1);
        }
    }
}
void Graph::print() {
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first << " " << T[i].second.second << " "<< T[i].first;
        cout << endl;
    }
}
int main(){
    int e,u,v,w;
    cin>>node>>e;
    Graph g(e);
    for(int i=0;i<e;i++){
        cin>>u>>v>>w;
        g.AddWeightedEdge(u,v,w);
    }
    g.kruskal();
    g.print();
    return 0;
}
