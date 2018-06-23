#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        int capacity;
        int top;
        int *arr;
    public:
        Stack(){
            capacity = 1000;
            top = -1;
            arr = (int*)malloc(capacity * sizeof(int));
        }
        void push(int data){
            if(top+1 == capacity)
                return;
            arr[++top] = data;
        }
        bool isEmpty(){
            return (top==-1);
        }
        int pop(){
            if(isEmpty())
                return -1;
            int temp = arr[top];
            top--;
            return temp;
        }
        int gettop(){
            if(isEmpty())
                return -1;
            return arr[top];
        }
};

int main()
{
    Stack s;
    int data;
    while(1){
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice\n";
        int t;
        cin>>t;
        if(t == 1){
            cout<<"Enter data to be pushed: ";
            cin>>data;
            s.push(data);
        }else if(t == 2){
            if(s.gettop() == -1)
                cout<<"The stack is empty\n";
            else
                cout<<"Popped item is "<<s.pop()<<endl;
        }else if(t == 3){
            break;
        }else{
            cout<<"Invalid choice\n";
        }
    }
}
