#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printPathsRecur(vector<vector<int> > graph, int s, int d, int arr[], int n, vector<bool> & visited)
{
    arr[n++] = s;
    visited[s] = true;
    if(s==d)
        printArray(arr, n);
    else{
        for(int i=0;i<graph[s].size();i++){
            if(visited[graph[s][i]] == false)
                printPathsRecur(graph, graph[s][i], d, arr, n, visited);
        }
    }
    visited[s] = false;
}

void printPaths(vector<vector<int> > graph, int V, int s, int d)
{
    int n = 0;
    int arr[1000];
    vector<bool> visited(V, false);
    printPathsRecur(graph, s, d, arr, n, visited);
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
    printPaths(graph, V, s, d);
}
