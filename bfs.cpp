#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> > graph, int V, int source)
{
    vector<bool> visited(V, false);
    queue<int> Q;
    Q.push(source);
    visited[source] = true;
    while(!Q.empty()){
        int temp = Q.front();
        cout<<temp<<" ";
        Q.pop();
        for(int i=0;i<graph[temp].size();i++){
            if(visited[graph[temp][i]] == false){
                visited[graph[temp][i]] = true;
                Q.push(graph[temp][i]);
            }
        }
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
    int source = 2;
    BFS(graph, V, source);
}
