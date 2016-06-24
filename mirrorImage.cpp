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


node* root1;

void mirror(node* root,node* root1)
{


if(root->right != NULL)
{
root1->left = newNode(root->right->data);
mirror(root->right,root1->left);
}


if(root->left != NULL)
{
root1->right = newNode(root->left->data);		   
mirror(root->left,root1->right);
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


mirror(root,root1);
cout<<"test data "<<root1->right->right->data<<endl;

return 0;

}

