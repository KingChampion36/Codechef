#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src;
    int dest;
    int wt;
};

void bellmanFord(vector<edge> graph, int V, int E, int source)
{
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for(int i=1;i<V;i++){
        for(int j=0;j<E;j++){
            int wt = graph[j].wt;
            int u = graph[j].src;
            int v = graph[j].dest;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
                dist[v] = dist[u] + wt;
        }
    }

    //Check for negative Cycle. If we get a shorter path, then there is a cycle.

    for(int i=0;i<E;i++){
        int u = graph[i].src;
        int v = graph[i].dest;
        int wt = graph[i].wt;

        if(dist[u] != INT_MAX && dist[v] > dist[u] + wt){
            cout<<"graph contains negative cycle";
            return;
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
    vector<edge> graph;

    for(int i=0;i<E;i++){
        edge temp;
        cin>>temp.src>>temp.dest>>temp.wt;
        graph.push_back(temp);
    }

    bellmanFord(graph, V, E, 0);
}
