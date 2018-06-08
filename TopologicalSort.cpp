#include<bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

vector <vector<int> > adj;
vector <int> color;
stack <int> st;
int node,edge;

void DFS_visit(int u)
{
    color[u]=GRAY;

    int n=adj[u].size();

    for(int i=0;i<n;i++){
        int v=adj[u][i];
        if(color[v]==WHITE)
            DFS_visit(v);
    }
    st.push(u);
    color[u]=BLACK;
}

void DFS(int s)
{
    if(color[s]==WHITE)
        DFS_visit(s);
    for(int i=0;i<node;i++){
        if(color[i]==WHITE)
            DFS_visit(i);
    }

}

int main()
{
    int u,v;
    cout<<"Enter Edge Number: ";
    cin>>edge;
    cout<<"Enter Node Number: ";
    cin>>node;

    adj.assign(node, vector<int>());
	color.assign(node, WHITE);

    for(int i=0;i<edge;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    DFS(0);
    for(int i=0;i<node;i++){
        u=st.top();
        st.pop();
        cout<<u<<" ";
    }
    return 0;
}
