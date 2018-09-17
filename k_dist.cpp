#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> > graph, int source, vector<int> & dist, int V)
{
    queue<int> Q;
    vector<bool> visited(V, false);
    Q.push(source);
    visited[source] = true;
    int level = 0;

    while(!Q.empty()){
        int nodeCount = Q.size();
        while(nodeCount--){
            int temp = Q.front();
            Q.pop();
            dist[temp] = max(dist[temp], level);
            for(int i=0;i<graph[temp].size();i++){
                if(visited[graph[temp][i]] == false){
                    visited[graph[temp][i]] = true;
                    Q.push(graph[temp][i]);
                }
            }
        }
        level++;
    }
}

int countKDist(vector<vector<int> > graph, int V, vector<int> marked, int k)
{
    vector<int> dist(V, -1);
    for(int i=0;i<marked.size();i++)
        BFS(graph, marked[i], dist, V);

    int counter = 0;
    for(int i=0;i<dist.size();i++){
        if(dist[i]!=-1 && dist[i] <= k)
            counter++;
    }
    return counter;
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
    int n;
    cin>>n;
    vector<int> marked(n);
    for(int i=0;i<n;i++)
        cin>>marked[i];

    int k;
    cin>>k;

    cout<<countKDist(graph, V, marked, k);
}

