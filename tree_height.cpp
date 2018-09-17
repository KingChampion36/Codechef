#include<bits/stdc++.h>
using namespace std;

int build_tree(int arr[], int n, vector<vector<int> > & graph)
{
    int root_index = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == -1)
            root_index = i;
        else{
            graph[i].push_back(arr[i]);
            graph[arr[i]].push_back(i);
        }
    }
    return root_index;
}

int BFS(int root_index, vector<vector<int> > graph, int V)
{
    queue<int> Q;
    vector<bool> visited(V, false);
    Q.push(root_index);
    visited[root_index] = true;
    int height = -1;
    while(!Q.empty()){
        int nodeCount = Q.size();
        while(nodeCount--){
            int temp = Q.front();
            Q.pop();
            for(int i=0;i<graph[temp].size();i++){
                if(visited[graph[temp][i]] == false){
                    visited[graph[temp][i]] = true;
                    Q.push(graph[temp][i]);
                }
            }
        }
        height++;
    }
    return height;
}

int main()
{
    int parent[] = {-1, 0, 0, 0, 3, 1, 1, 2 };
    int n = sizeof(parent) / sizeof(parent[0]);
    vector<vector<int> > graph(n);
    int root_index = build_tree(parent, n, graph);
    int height = BFS(root_index, graph, n);
    cout << "Height of N-ary Tree=" << height;
    return 0;
}
