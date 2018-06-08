#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n<=1)
        return false;
    if(n==2)
        return true;
    for(int i=2;i<=ceil(sqrt(n));i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

bool isPrimeBinary(int n)
{
    int counter = 0;
    while(n){
        int r = n%2;
        if(r == 1)
            counter++;
        n = n/2;
    }
    if(isPrime(counter)){
        //cout<<counter<<" "<<"Prime ";
        return true;
    }
    //cout<<counter<<" ";
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int l, r;
	    cin>>l>>r;
	    int counter = 0;
	    for(int i=l;i<=r;i++){
	        if(isPrimeBinary(i)){
                //cout<<i<<endl;
	            counter++;
	        }
	    }
	    cout<<counter<<endl;
	}
	return 0;
}
