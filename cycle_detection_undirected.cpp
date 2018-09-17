#include<bits/stdc++.h>
using namespace std;

bool explore(vector<vector<int> > graph, int source, vector<bool> & visited, int parent)
{
    visited[source] = true;
    for(int i=0;i<graph[source].size();i++){
        if(visited[graph[source][i]] == false){
            if (explore(graph, graph[source][i], visited, source))
                return true;
        }else if(graph[source][i] != parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<vector<int> > graph, int V)
{
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        if(visited[i] == false)
            if(explore(graph, i, visited, -1))
                return true;
    }
    return false;
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
    cout<<isCyclic(graph, V);
}

