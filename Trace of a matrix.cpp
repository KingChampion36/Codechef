#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		int maxTrace = 0;
		for(int i=0;i<n;i++)
			maxTrace+=arr[i][i];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(arr[i][j] > maxTrace)
				    maxTrace = arr[i][j];
		
		int trace = 0;
		int k = 1;
		while(1){
			int i=0;
			int j=k;
			trace = 0;
			while(i < n-1 && j < n){
				trace += arr[i][j];
				i++;
				j++;
			}
			if(trace > maxTrace)
				maxTrace = trace;
			k++;
			if(k == n-1)
				break;
		}
		k = 1;
		while(1){
			int i=k;
			int j=0;
			trace = 0;
			while(i < n && j < n-1){
				trace += arr[i][j];
				i++;
				j++;
			}
			if(trace > maxTrace)
				maxTrace = trace;
			k++;
			if(k == n-1)
				break;
		}
		cout<<maxTrace<<endl;
	}
} 