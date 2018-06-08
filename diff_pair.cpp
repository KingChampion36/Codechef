#include <bits/stdc++.h>
using namespace std;

bool isPair(int arr[], int n, int diff)
{
    map<int, int> m;
    for(int i=0;i<n;i++)
        m[arr[i]] = 1;
    for(int i=0;i<n;i++){
        arr[i] = arr[i]-diff;
        if(m[arr[i]] == 1)
            return true;
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, diff;
	    cin>>n>>diff;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    if(isPair(arr, n, diff))
	        cout<<"1\n";
	    else
	        cout<<"-1\n";
	}
	return 0;
}
