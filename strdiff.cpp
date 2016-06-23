#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int S;
string a,b;
int max_len = 0;
int n;

int max(int a ,int b,int c)

{

//cout<<" max called for "<<a<<","<<b<<" and "<<c<<endl; 

   if (a>b)
       if (a>c)
            return a;
       else
            return c;
   else    
       if(b>c)
            return b;
       else
            return c;
}  

int M(int i,int j)
{
  
 //cout <<"M called for index "<<i<<" and "<<j<<endl;
 int n_i = i;
 int n_j = j;
    
 int mis_match = 0;
    
 while(mis_match <= S and n_i<n and n_j<n)
 {
 //cout<<" in loop "<<endl;
  //if(i ==0 and j == 3)
  //cout<<"comparing "<<a[n_i]<<" and "<<b[n_j]<<endl;
  if(mis_match != S)	
  {		
  	 //cout<<" in if "<<endl;	
     if(a[n_i] != b[n_j])
     {
     
     mis_match++;
     //if(i ==0 and j == 3)
     //cout<<"found mismatch "<<endl;
      }
   }   
   else
   	if(a[n_i] != b[n_j])
   		break;

n_i++;
n_j++;
		      
     
 }
  
  //if(i ==0 and j == 3)
  //cout<<"mismatch no is "<<mis_match<<endl;  
    
 if(max_len < n_i - i)   
 max_len = n_i - i;   
  
  //if(i ==0 and j == 3)   
  //cout<<" max len is "<<max_len<<endl;   
     
 if(i+S<n && j+S<n)   
 max( M(i+1,j+1),M(i+1,j),M(i,j+1) );
    
    
return max_len;    
}


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    max_len = 0;
    int res = 0;
    cin>>S>>a>>b;
    //cout <<" S is "<<S<<endl;
    //cout<<" strings are "<<a<< " and "<<b<<endl;
    n = a.length();
    res= M(0,0);
    cout<<res<<endl;
    }
    return 0;
}

