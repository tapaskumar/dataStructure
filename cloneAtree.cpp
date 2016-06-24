#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
int data;
node* left;
node* right;
};

node* root1;

node* newNode(int k)
{
node* temp = new node;
temp->data = k;
temp->left = temp->right = NULL;
return temp;
}

void clone(node* root,node* root1)
{
if(root->left != NULL)
{
root1->left = newNode(root->left->data);
clone(root->left,root1->left);
}

if(root->right != NULL)
{
root1->right = newNode(root->right->data);
clone(root->right,root1->right);
}    	

	   
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
    

root1 = newNode(root->data);
clone(root,root1);

cout<<" new data is "<<root1->left->data<<endl;

return 0;

}

