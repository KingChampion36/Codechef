#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str)
{
    string str1 = "";
    for(int i=0;i<str.size();i++){
        if(isalnum(str[i]))
            str1+=str[i];
    }
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    if(str1 == str2)
        return true;
    return false;

}

int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
	    string str;
	    getline(cin, str);
	    for(int i=0;i<str.size();i++)
	        str[i] = tolower(str[i]);
	    //cout<<str<<endl;
	    if(checkPalindrome(str))
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";

	}
	return 0;
}
