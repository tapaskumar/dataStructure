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


void boundary(node* root,bool left,bool right)
{
if(root!= NULL)
cout<<root->data<<" ";

if(left)
	if(root->left)
		boundary(root->left,1,0);
	else if(root->right)
		boundary(root->right,1,0);

if(right)
	if(root->right)
		boundary(root->right,0,1);
	else if(root->left)
		boundary(root->left,0,1);
}


int main()
{
    node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->left->left  = newNode(10);
    root->left->left->right = newNode(14);
    

//cout<<root->left->data<<" "<<root->right->data<<endl;

boundary(root,1,1);

cout<<endl;

return 0;

}
	
