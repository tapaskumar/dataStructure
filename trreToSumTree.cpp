#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>


using namespace std;

struct node
{
int data;
node* left;
node* right;
};

node* newNode(int k)
{
node* temp = new node;
temp->data = k;
temp->left = temp->right = NULL;
return temp;
}

int sumtree(node* root)
{
if(root->left == NULL && root->right == NULL)
return root->data;

root->data = sumtree(root->left) + sumtree(root->right);
return root->data;

}


int main()
{
    node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    
sumtree(root);

cout<<" data is "<<root->data<<endl;
return 0;

}

