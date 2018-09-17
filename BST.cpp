#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

void inOrder(node *root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

node* createNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* getMax(node *root)
{
    if(root == NULL)
        return NULL;

    while(root->right)
        root = root->right;
    return root;
}

node* getMin(node *root)
{
    if(root == NULL)
        return NULL;

    while(root->left)
        root = root->left;
    return root;
}

void insertData(node* &root, int data)
{
    if(root == NULL){
        root = createNode(data);
        return;
    }
    if(data < root->data){
        if(root->left)
            insertData(root->left, data);
        else
            root->left = createNode(data);
    }else if(data > root->data){
        if(root->right)
            insertData(root->right, data);
        else
            root->right = createNode(data);
    }
}

node* deleteData(node *root, int data)
{
    if(root == NULL)
        return NULL;
    if(data < root->data)
        root->left = deleteData(root->left, data);
    else if(data > root->data)
        root->right = deleteData(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left == NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *maxNode = getMax(root->left);
        swap(root->data, maxNode->data);
        root->left = deleteData(root->left, data);
    }
    return root;
}

int main()
{
   node *root = NULL;
   insertData(root, 15);
   insertData(root, 10);
   insertData(root, 25);
   insertData(root, 7);
   insertData(root, 9);
   insertData(root, 17);
   inOrder(root);
   cout<<endl;
   root = deleteData(root, 15);
   root = deleteData(root, 7);
   inOrder(root);
   cout<<endl;
   cout<<getMax(root)->data<<endl;
   cout<<getMin(root)->data<<endl;
}
