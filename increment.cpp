#include<iostream>
#include<stack>
using namespace std;

struct node
{
int data;
node* next;
};

int add(node* temp,int b)
{
int sum = temp->data = temp->data + b;

if(sum >= 10)
{
temp->data = 0;
return 1;
}
else
return 0; 

}


int increment(node* temp)
{
if(temp == NULL)
return 1;

int carry = add(temp,increment(temp->next));
return carry;
}



void display(node* head)
{
node* temp = head;

while(temp != NULL)
{
cout<<temp->data<<" ";
temp = temp->next;
}

}


void init(node** head,int n)
{
(*head) = new node;
(*head)->data = n;
(*head)->next = NULL;
}

void insert(node* head,int n)
{
node* temp = head;

while(temp->next != NULL)
temp = temp->next;

temp->next = new node;
temp->next->data = n;
temp->next->next = NULL;
} 

int main()
{

int s = 5;
int val;
node* head = NULL;

for(int i=0;i<s;i++)
{
cin>>val;
if(head == NULL)
init(&head,val);
else
insert(head,val);
}


cout<<"\n";
increment(head);
cout<<"\n";
display(head);
}



