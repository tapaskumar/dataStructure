#include<iostream>
#include<stack>
using namespace std;

struct node
{
int data;
node* next;
};

void insert(node* head,int n)
{
node* temp = head;

while(temp->next != NULL)
temp = temp->next;

temp->next = new node;
temp->next->data = n;
temp->next->next = NULL;
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


int addList(node* first,node* second)
{

int carry = 0;
int sum = 0;
node* dummy = new node;
dummy->next = NULL;
node* temp = dummy;


while(first != NULL || second != NULL)
{
sum = carry + (first?first->data:0) + (second?second->data:0);

if(sum >= 10)
{
sum = sum%10;
carry = 1;
}
else
carry = 0;

insert(temp,sum);
temp = temp->next;

(first?first = first->next:first);
(second?second = second->next:second);
}

display(dummy->next);

}

void init(node** head,int n)
{
(*head) = new node;
(*head)->data = n;
(*head)->next = NULL;
}



int main()
{

int s1 = 5;
int s2 = 5;

int val;

node* head1 = NULL;
node* head2 = NULL;

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

cout<<"\n";
addList(head1,head2);

}



