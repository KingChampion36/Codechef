#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
	    string str1, str2;
	    cin>>str1>>str2;
	    map<char, int> m;
	    for(int i=0;i<str1.size();i++)
	        m[str1[i]] = 1;
	    bool flag = false;
	    for(int i=0;i<str2.size();i++){
	        if(m[str2[i]] == 1){
	            cout<<"1\n";
	            flag = true;
	            break;
	        }
	    }
	    if(flag == false)
	        cout<<"0\n";
    }
    return 0;
}
