#include<bits/stdc++.h>
using namespace std;

bool allTrue(vector<bool> visited)
{
    for(int i=0;i<visited.size();i++){
        if(visited[i] == false)
            return false;
    }
    return true;
}

void explore(vector<vector<int> > graph, int source, vector<bool> & visited)
{
    visited[source] = true;
    for(int i=0;i<graph[source].size();i++){
        if(visited[graph[source][i]] == false)
            explore(graph, graph[source][i], visited);
    }
}

int mother_vertex(vector<vector<int> > graph, int V)
{
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        explore(graph, i, visited);
        if(allTrue(visited))
            return i;
        else{
            for(int j=0;j<V;j++)
                visited[j] = false;
        }
    }
    return -1;
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
    }
    cout<<mother_vertex(graph, V);
}
