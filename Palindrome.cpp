#include<bits/stdc++.h>
using namespace std;

int getDigits(int num)
{
    int counter = 0;
    while(num){
        num = num/10;
        counter++;
    }
    return counter;
}

bool checkPalindrome(int num)
{
    int digits = getDigits(num);
    while(digits > 1){
        int d1 = num%10;
        int d2 = num/(int)pow(10, digits-1);
        if(d1 != d2)
            return false;
        num = num - d2*(int)pow(10, digits-1);
        num = num/10;
        digits-=2;
    }
    return true;
}

int main()
{
    int num;
    cin>>num;
    if(checkPalindrome(num))
        cout<<"palindrome";
    else
        cout<<"not a palindrome";
}