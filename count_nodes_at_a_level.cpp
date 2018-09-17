#include<bits/stdc++.h>
using namespace std;

int countNodes(vector<vector<int> > graph, int V, int level)
{
    int l = 0;
    vector<bool> visited(V, false);
    queue<int> Q;
    Q.push(0);
    visited[0] = true;
    int counter = 0;

    while(!Q.empty()){
        int nodeCount = Q.size();
        while(nodeCount--){
            int temp = Q.front();
            Q.pop();
            if(l == level){
                cout<<temp<<" ";
                counter++;
            }
            for(int i=0;i<graph[temp].size();i++){
                if(visited[graph[temp][i]] == false){
                    Q.push(graph[temp][i]);
                    visited[graph[temp][i]] = true;
                }
            }
        }
        if(l == level)
            break;
        l++;
    }
    cout<<endl;
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
    }
    int level;
    cin>>level;
    cout<<countNodes(graph, V, level);
}

