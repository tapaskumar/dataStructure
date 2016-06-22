#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

struct node
{
int data;
struct node* next;
};

node* head1 = NULL;
node* head2 = NULL;

void display(node* head)
{
node* temp = head;

while(temp!=NULL)
{
cout<<temp->data<<" ";
temp = temp->next;
}
cout<<endl;
}


void merge(node* h1,node* h2)
{
node *p1 = h1;
node *p2 = h2;

node* dummy = new node;

int res = 0;


node* temp3 = dummy;
while(p1 != NULL && p2 != NULL)
{


if(p1->data < p2->data)
	{
	res = p1->data;
	p1 = p1->next;
	}
else
	{
	res = p2->data;
	p2 = p2->next;
	}	
	temp3->next = new node;
	temp3->next->data = res;
	temp3->next->next = NULL;				

	temp3 = temp3->next;
}

if(p1 == NULL)
temp3->next = p2;
else
temp3->next = p1;

node* head3 = dummy->next;
display(head3);

}





void init(node** head,int n)
{
(*head) = new node;
(*head)->data = n;
(*head)->next = NULL;  
}


void insert(node* head,int n)
{

	node *temp = head;	
	while(temp->next != NULL)
		temp = temp->next;
		
	node* temp1 = new node;
	temp1->data = n;
	temp1->next = NULL;
	
	temp->next = temp1;
}
	

int main()
{
int val;
int s1 = 5,s2 = 5;
for(int i=0;i<s1;i++)
{
 cin>>val;
 if(head1 == NULL)
 init(&head1,val);
 else
 insert(head1,val);
}


for(int i=0;i<s2;i++)
{
 cin>>val;
 if(head2 == NULL)
 init(&head2,val);
 else
 insert(head2,val);
}

//display(head1);
//display(head2);

merge(head1,head2);


}
