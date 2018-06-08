#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int arr1[n];
        int arr2[n];
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        sort(arr1, arr1+n);
        sort(arr2, arr2+n);
        int ans = 0;
        int j = n-1;
        for(int i=0;i<n;i++){
            ans = ans + arr1[i]*arr2[j];
            j--;
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}
