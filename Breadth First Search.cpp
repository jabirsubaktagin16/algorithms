#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int visited[100];
void bfs(int s,int n)
{
    for(int i=0;i<n;i++)
        visited[i]=0;
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        cout<<u<<" ";
        Q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                visited[v]=1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int s,n,edge,u,v;
    cout<<"Enter Edge Number: ";
    cin>>edge;
    cout<<endl;
    cout<<"Enter Node Number: ";
    cin>>n;
    cout<<endl;
    for(int i=0;i<edge;i++)
    {
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    cout<<"Enter Starting Node: ";
    cin>>s;
    cout<<endl;
    bfs(s,n);
    return 0;
}
