#include<bits/stdc++.h>
using namespace std;

bool explore(vector<vector<int> > graph, int source, vector<bool> & visited, vector<bool> recStack)
{
    if(visited[source] == false){
        visited[source] = true;
        recStack[source] = true;

        for(int i=0;i<graph[source].size();i++){
            if(visited[graph[source][i]] == false && explore(graph, graph[source][i], visited, recStack))
                return true;
            if(recStack[graph[source][i]] == true)
                return true;
        }
    }
    recStack[source] = false;
    return false;
}

bool isCyclic(vector<vector<int> > graph, int V)
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for(int i=0;i<V;i++){
        if(explore(graph, i, visited, recStack))
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
    }
    cout<<isCyclic(graph, V);
}
