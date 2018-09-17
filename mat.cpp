#include <bits/stdc++.h>
using namespace std;

int minDist(vector<vector<char> > mat, vector<vector<int> >&cost, vector<vector<bool> >&visited, int i, int j ,int dest_i, int dest_j, int n, int m)
{
    cout<<"here we are i= "<<i<<" j="<<j<<endl;
    if(i==dest_i && j==dest_j){
        visited[i][j]=true;
        return 0;
    }
    if(i<0 || i>=n || j<0 || j>=m)
        return INT_MAX;
    if(visited[i][j]==true)
    {
        if(cost[i][j]==-1)
            return INT_MAX-1000;
        else
            return cost[i][j];
    }
    visited[i][j] = true;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX,d=INT_MAX;
    if(j>0 && mat[i][j-1]!='0')
        a=1+minDist(mat,cost,visited,i,j-1,dest_i,dest_j,n,m);
    if(i>0 && mat[i-1][j]!='0')
        b=1+minDist(mat,cost,visited,i-1,j,dest_i,dest_j,n,m);
    if(j<m-1 && mat[i][j+1]!='0')
        c=1+minDist(mat,cost,visited,i,j+1,dest_i,dest_j,n,m);
    if(i<n-1 && mat[i+1][j]!='0')
        d=1+minDist(mat,cost,visited,i+1,j,dest_i,dest_j,n,m);
    cost[i][j]=min(min(a,b),min(c,d));
    return cost[i][j];
}

int main() {
	int m, n;
	cin>>m>>n;
	vector<vector<char> > matrix(m);
	vector<vector<int> > cost(m);
	vector<vector<bool> > visited(m);
	int src_i,src_j,dest_i,dest_j;
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        char temp;
	        cin>>temp;
	        matrix[i].push_back(temp);
	        cost[i].push_back(-1);
	        visited[i].push_back(false);
	        if(matrix[i][j] == 's'){
                src_i = i;
                src_j = j;
	        }else if(matrix[i][j] == 'd'){
                dest_i = i;
                dest_j = j;
            }
	    }
	}
	for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<matrix[i][j]<<" "<<cost[i][j]<<" "<<visited[i][j]<<" ";
        cout<<endl;
    }
	cout<<minDist(matrix, cost, visited, src_i,src_j, dest_i, dest_j, m, n)<<endl;
	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
	}
	return 0;
}
