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

int mother_vertex(vector<vector<int> > graph, int V)
{
    vector<bool> visited(V, false);
    int candidate;
    for(int i=0;i<V;i++){
        if(visited[i] == false){
            explore(graph, i, visited);
            candidate = i;
        }
    }

    //cout<<candidate<<endl;

    for(int i=0;i<V;i++)
        visited[i] = false;

    explore(graph, candidate, visited);

    for(int i=0;i<V;i++){
        if(visited[i] == false){
            //cout<<i<<endl;
            return -1;
        }
    }
    return candidate;
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
