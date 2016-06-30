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

int n = 51;


bool pairSum(node* root,int sum)
{
if(root)
sum += root->data;
else
return false;

if(sum < n)
return ( pairSum(root->left,sum) || pairSum(root->right,sum) ); 	  

else if (sum == n)
	return true;
	
else
	return false;			   
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
    
if(pairSum(root,0))
cout<<" sum found \n";

return 0;

}

