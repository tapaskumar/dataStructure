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

vector<int>v1;
vector<int>v2;

void lca(node* root,int n,vector<int>& v)
{
int val = root->data;

//cout<<val<<"  is pushed "<<endl;	
v.push_back(val);

if(root->data != n)
{

if(root->data > n)
	lca(root->left,n,v);
else
	lca(root->right,n,v);				   	
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
    
int n1 = 10,n2 = 22;

lca(root,n1,v1);
lca(root,n2,v2);

int ancestor;

for(int i=0;i<min(v1.size(),v2.size());i++)
{
if(v1[i] == v2[i])
ancestor = v1[i];
else
break;
}

cout<<"lowest common ancestor is "<<ancestor<<endl;

return 0;

}

