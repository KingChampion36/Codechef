#include <bits/stdc++.h>
using namespace std;

int getSum(stack<int> s)
{
    int sum = 0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    return sum;
}

int maxSum(stack<int> s1, stack<int> s2, stack<int> s3)
{
    while(!s1.empty() && !s2.empty() && !s3.empty()){
        int sum1 = getSum(s1);
        int sum2 = getSum(s2);
        int sum3 = getSum(s3);

        if(sum1 == sum2 && sum2 == sum3)
            return sum1;
        if(max(sum1, max(sum2, sum3)) == sum1)
            s1.pop();
        if(max(sum1, max(sum2, sum3)) == sum2)
            s2.pop();
        if(max(sum1, max(sum2, sum3)) == sum3)
            s3.pop();
    }
    return -1;
}

int main()
{
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    s1.push(1);
    s1.push(1);
    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2.push(2);
    s2.push(3);
    s2.push(4);

    s3.push(1);
    s3.push(4);
    s3.push(1);
    s3.push(1);

    cout<<maxSum(s1, s2, s3);
}
