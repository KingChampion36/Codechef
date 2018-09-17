#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int> > >graph, int V, int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
    Q.push(make_pair(dist[source], source));

    while(!Q.empty()){
        pair<int, int> temp = Q.top();
        Q.pop();
        int u = temp.second;

        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i].first;
            int wt = graph[u][i].second;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
                Q.push(make_pair(dist[v], v));
            }
        }
    }

    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
}

int main()
{
    int V, E;
    cin>>V>>E;
    vector<vector<pair<int, int> > > graph(V);

    for(int i=0;i<E;i++){
        int a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    dijkstra(graph, V, 0);
}
