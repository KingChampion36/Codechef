#include<bits/stdc++.h>
using namespace std;

void explore(vector<vector<int> > graph, int source, vector<bool> & visited)
{
    visited[source] = true;
    cout<<source<<" ";
    for(int i=0;i<graph[source].size();i++){
        if(visited[graph[source][i]] == false)
            explore(graph, graph[source][i], visited);
    }
}

void dfs(vector<vector<int> > graph, int V)
{
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        if(visited[i] == false)
            explore(graph, i, visited);
    }
}

int main()
{
    int V, E;
    cin>>V>>E;
    vector<vector<int> > graph(V);
    for(int i=0;i<E;i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph, V);
}
