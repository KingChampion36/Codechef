#include <bits/stdc++.h>
using namespace std;

void getStar(int arr[], int n)
{
    int max_so_far = arr[n-1];
    stack<int> s;
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        if(arr[i] > max_so_far){
            s.push(arr[i]);
            max_so_far = arr[i];
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void getSuperStar(int arr[], int n)
{
    int maxm = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > maxm){
            maxm = arr[i];
        }
    }
    int counter = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == maxm)
            counter++;
    }
    if(counter == 1)
        cout<<maxm<<endl;
    else
        cout<<"-1"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        getStar(arr, n);
        getSuperStar(arr, n);
    }
	return 0;
}
