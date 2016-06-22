#include<iostream>
using namespace std;

int *a;

int binaryInc(int start,int end,int key)
{

int mid = (start + end)/2;

if(key == a[start])
return start;

if(key == a[end])
return end;

else if(a[start] < key < a[mid]) 
binaryInc(start,mid,key);

else if (a[mid+1] < key <a[end])
binaryInc(mid+1,end,key);

else 
return -1;
}


int binaryDec(int start,int end,int key)
{

int mid = (start + end)/2;

if(key == a[start])
return start;

else if(key == a[end])
return end;

else if(a[start] > key > a[mid]) 
binaryInc(start,mid,key);

else if (a[mid+1] > key > a[end])
binaryInc(mid+1,end,key);

else
return -1;
}

int main()
{
int n,key;
cin>>n;
cin>>key;
a = new int[n];

for(int i=0;i<n;i++)
cin>>a[i];

int max_index;

for(int i=0;i<n;i++)
{

if(a[i]>a[i+1])
	{
	max_index = i;
	break;
	}
}


int res1 = binaryInc(0,max_index,key);
int res2 = binaryDec(max_index+1,n-1,key);

cout<<" result is "<<res1<<" "<<res2<<endl;
}
