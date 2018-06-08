#include<bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

vector<vector<int> > adj;
vector<vector<int> > adj2;
vector<int> color;
int edge,node;
stack<int> st;

void DFS_Visit(int u)
{
	color[u] = GRAY;

	int n = adj[u].size();
	for(int i = 0; i < n; i++){
		int v = adj[u][i];
		if(color[v] == WHITE)
			DFS_Visit(v);
	}
    st.push(u);
	color[u] = BLACK;
}

void DFS(int s)
{
	if(color[s] == WHITE)
        DFS_Visit(s);

	for(int i = 0; i < node; i++){
		if(color[i] == WHITE)
			DFS_Visit(i);
	}
}

void DFS_Reverse_Visit(int u)
{
	color[u] = GRAY;
	cout << u << " " ;

	int n = adj2[u].size();
	for(int i = 0; i < n; i++){
		int v = adj2[u][i];
		if(color[v] == WHITE)
			DFS_Reverse_Visit(v);
	}
 	color[u] = BLACK;
}

void DFS_Reverse(int s)
{
	int i=1;
	cout << endl << i++ <<": ";

	if(color[s] == WHITE)
        DFS_Reverse_Visit(s);

	while(!st.empty()){
		if(color[st.top()] == WHITE){
            cout << endl << i++ <<": " ;
			DFS_Reverse_Visit(st.top());
		}
        st.pop();
	}
}

int main()
{
	int u, v;

	cout << "Enter Edge Number: ";
	cin >> edge;
	cout << "Enter Node Number: ";
	cin >> node;

	adj.assign(node, vector<int>());
	adj2.assign(node, vector<int>());
	color.assign(node, WHITE);

	for(int i = 0; i < edge; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}

	DFS(0);
	color.assign(node, WHITE);
	DFS_Reverse(st.top());

	return 0;
}
