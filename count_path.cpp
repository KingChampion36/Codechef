#include<bits/stdc++.h>
using namespace std;

void countPathsRecur(vector<vector<int> > graph, int s, int d, vector<bool> & visited, int & pathCount)
{
    visited[s] = true;
    if(s == d)
        pathCount++;
    else{
        for(int i=0;i<graph[s].size();i++){
            if(visited[graph[s][i]] == false)
                countPathsRecur(graph, graph[s][i], d, visited, pathCount);
        }
    }
    visited[s] = false;
}

int countPaths(vector<vector<int> > graph, int V, int s, int d)
{
    vector<bool> visited(V, false);
    int pathCount = 0;
    countPathsRecur(graph, s, d, visited, pathCount);
    return pathCount;
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
    int s, d;
    cin>>s>>d;
    cout<<countPaths(graph, V, s, d);
}
