#include<bits/stdc++.h>
using namespace std;

void explore(vector<vector<int> > graph, int source, vector<bool> & visited)
{
    stack<int> s;
    s.push(source);
    visited[source] = true;

    while(!s.empty()){
        int temp = s.top();
        s.pop();
        cout<<temp<<" ";
        for(int i=0;i<graph[temp].size();i++){
            if(visited[graph[temp][i]] == false){
                s.push(graph[temp][i]);
                visited[graph[temp][i]] = true;
            }
        }
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
    }
    dfs(graph, V);
}
