#include<bits/stdc++.h>
using namespace std;

void explore(vector<vector<int> > graph, int source, vector<bool> & visited)
{
    visited[source] = true;
    for(int i=0;i<graph[source].size();i++){
        if(visited[graph[source][i]] == false)
            explore(graph, graph[source][i], visited);
    }
}

void transitive_closure(vector<vector<int> > graph, int V)
{
    vector<vector<bool> > trans(V);
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        explore(graph, i, visited);
        for(int j=0;j<V;j++)
            trans[i].push_back(visited[j]);
        for(int j=0;j<V;j++)
            visited[j] = false;
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<trans[i][j]<<" ";
        cout<<endl;
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
    }
    transitive_closure(graph, V);
}
