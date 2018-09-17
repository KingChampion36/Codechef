#include<bits/stdc++.h>
using namespace std;

int getMaxEdges(vector<vector<int> > graph, int V)
{
    int colour[2] = {0, 0};
    int color = 0;
    queue<int> Q;
    vector<bool>visited(V+1, false);
    Q.push(1);
    visited[1] = true;
    while(!Q.empty()){
        int nodeCount = Q.size();
        while(nodeCount--){
            int temp = Q.front();
            Q.pop();
            colour[color]++;
            for(int i=0;i<graph[temp].size();i++){
                if(visited[graph[temp][i]] == false){
                    Q.push(graph[temp][i]);
                    visited[graph[temp][i]] = true;
                }
            }
        }
        color = !color;
    }

    //cout<<colour[0]<<" "<<colour[1]<<endl;
    return (colour[0]*colour[1])-(V-1);
}

int main()
{
    int V;
    cin>>V;
    vector<vector<int> > graph(V+1);
    for(int i=0;i<V-1;i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<<getMaxEdges(graph, V);
}
