#include<bits/stdc++.h>
using namespace std;
 
bool check(int a, int b, int c)
{
    if(a == b+c || b == a+c || c == a+b)
        return true;
    return false;
}
 
bool isDynamic(string str)
{
    map<char, int> m;
    for(int i=0;i<str.size();i++)
        m[str[i]]++;
    vector<int> v;
    map<char, int>:: iterator it = m.begin();
    while(it!=m.end()){
        v.push_back(it->second);
        it++;
    }
    if(v.size() <= 2)
    	return true;
    for(int i=0;i<=v.size()-3;i+=3){
        if(!check(v[i], v[i+1], v[i+2]))
            return false;
    }
    return true;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(isDynamic(str))
            cout<<"Dynamic\n";
        else
            cout<<"Not\n";
    }
} 
