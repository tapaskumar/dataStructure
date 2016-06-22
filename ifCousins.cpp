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

bool sameparent()
{

}

int getHeight(node* root,node* n,int height)
{

if(root->data == n->data)
return height;	

if(root == NULL)
return 0;

h1 = getHeight(root->left,n,height+1);
h2 = getHeight(root->right,n,height+1);	

return h1 + h2;

}

bool cousins(node* root,node* n1,node* n2)
{

if( getHeight(root,n1,1) != getHeight(root,n2,1))
return false;

else
	{
		if( sameparent(root,n1,n2))
			return false;
		else 
			return true;	
	
	}		 


}


node* newNode(int k)
{
node* temp = new node;
temp->data = k;
temp->left = temp->right = NULL;
return temp;
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



return 0;

}

