#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        list<pair<int, int> > *adj;

    public:
        Graph(int v);
        void addEdge(int u, int v, int w);
        void primMST();
};

Graph::Graph(int v)
{
    V = v;
    adj = new list<pair<int, int> >[V];
}

void Graph:: addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph:: primMST()
{
    int src = 0;

    //To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);


    set<pair<int, int> > s;
    s.insert(make_pair(0, src));
    key[src] = 0;

    while(!s.empty()){
        pair<int, int> temp = *(s.begin());
        s.erase(s.begin());
        int u = temp.second;
        inMST[u] = true;

        list<pair<int, int> >::iterator it = adj[u].begin();
        while(it!=adj[u].end()){
            int v = (*it).first;
            int weight = (*it).second;

            if(inMST[v] == false && key[v] > weight){
                //if(key[v] != INF)
                  //  s.erase(make_pair(key[v], v));
                key[v] = weight;
                s.insert(make_pair(key[v], v));
                parent[v] = u;
            }
            it++;
        }
    }

    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();

    return 0;
}

