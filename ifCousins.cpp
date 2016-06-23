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

bool sameparent(node* root,node* n1,node* n2)
{
if (root->left == NULL || root->right == NULL)
	return false;	

if(root->left == n1 && root->right == n2)
	return true;
	
if( sameparent(root->left,n1,n2) || sameparent(root->right,n1,n2) )
	return true;
		
}

int getHeight(node* root,node* n,int height)
{

if(root == NULL)
return 0;

if(root->data == n->data)
return height;	

int h1 = getHeight(root->left,n,height+1);
int h2 = getHeight(root->right,n,height+1);	

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
    root->right->left        = newNode(11);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

	if ( cousins(root,root->right->left,root->left->right) )
		cout<<" they are cousins "<<endl;


return 0;

}

