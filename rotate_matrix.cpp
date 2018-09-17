#include<bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int> > & arr, int m, int n)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

void rotate_matrix(vector<vector<int> > & arr, int m, int n, int k)
{
    vector<int> temp(m);
    int i = 0;
    k = k % n;
    while(i<k){
        for(int j=0;j<m;j++){
            temp[j] = arr[j][n-1];
        }
        for(int p=0;p<m;p++){
            for(int q=n-2;q>=0;q--){
                arr[p][q+1] = arr[p][q];
            }
        }
        for(int p=0;p<n;p++){
            arr[p][0] = temp[p];
        }
        i++;
    }
}

int main()
{
    int m;
    int n;
    cin>>m>>n;
    vector<vector<int> > arr(m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            arr[i].push_back(temp);
        }
    }
    int k;
    cin>>k;
    rotate_matrix(arr, m, n, k);
    cout<<"The rotated matrix is:\n";
    printArray(arr, m, n);
}
