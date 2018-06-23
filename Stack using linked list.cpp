#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

class Stack{
    private:
        node *head;
        node* createNode(int data){
            node *temp = new node;
            temp->data = data;
            temp->next = NULL;
            return temp;
        }
    public:
        Stack(){
            head = NULL;
        }
        bool isEmpty(){
            return (head == NULL);
        }
        void push(int data){
            if(isEmpty()){
                head = createNode(data);
                return;
            }
            node *temp = createNode(data);
            temp->next = head;
            head = temp;
        }
        int top(){
            if(isEmpty()){
                return -1;
            }
            return (head->data);
        }
        void pop(){
            if(isEmpty())
                return;
            node *temp = head;
            head = head->next;
            delete temp;
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
            if(s.top() == -1)
                cout<<"The stack is empty\n";
            else{
                cout<<"Popped item is "<<s.top()<<endl;
                s.pop();
            }
        }else if(t == 3){
            break;
        }else{
            cout<<"Invalid choice\n";
        }
    }
}
