#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
        queue<int> Q;
    public:
        void push(int data){
            Q.push(data);
            while(Q.front() != data){
                int temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
        }
        int top(){
            return (Q.front());
        }
        void pop(){
            Q.pop();
        }
        bool isEmpty(){
            return (Q.size() == 0);
        }
};

int main()
{
    Stack s;
    for(int i=1;i<=5;i++)
        s.push(i);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top();
    return 0;
}
