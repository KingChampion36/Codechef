#include<bits/stdc++.h>
using namespace std;

int minEdges(vector<vector<int> > graph, int V, int s, int d)
{
    vector<bool> visited(V, false);
    queue<int> Q;
    Q.push(s);
    visited[s] = true;
    int level = 0;
    while(!Q.empty()){
        int nodeCount = Q.size();
        while(nodeCount--){
            int temp = Q.front();
            Q.pop();
            if(temp == d)
                return level;
            for(int i=0;i<graph[temp].size();i++){
                if(visited[graph[temp][i]] == false){
                    visited[graph[temp][i]] = true;
                    Q.push(graph[temp][i]);
                }
            }
        }
        level++;
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
        graph[b].push_back(a);
    }
    int s, d;
    cin>>s>>d;
    cout<<minEdges(graph, V, s, d);
}
