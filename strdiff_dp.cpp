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



int cal_len(int ***M)
{


M[0][0][0] = 0;
int mis_match = 0;
			


int len = 0;
for(int i = 0;i<n-S;i++)
{
	for(int j =0;j<n-S;j++)
	{
		if(a[i]!= b[j]) 
			M[i][j][0] = 1;
		else
			M[i][j][0] = 0;
				
		for (int k=1;k<min(n-i,n-j);k++)
		{
		
		if(a[i+k] != b[j+k])
			M[i][j][k] = M[i][j][k-1] + 1;		
		else 
			M[i][j][k] = M[i][j][k-1];
			
		if(M[i][j][k] > S)
			break;							
		if(M[i][j][k] == S)			
			len = max(len, k);
			
				
		//cout<<" calculating for "<<i<<" and "<<j<<"and length k = "<<k<<" mismatch = "<<M[i][j][k]<<endl;	
		}	
			
	}
	
}

 return len+1;   
    

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
    n = a.length();    
    int ***M = new int**[n];
    for (i = 0; i <n; ++i) 
    {
    arr[i] = new int*[n];
  	for (j = 0; j <n; ++j)
    arr[i][j] = new int[n];
	}
	
    res= cal_len(M);
    
    for (i = 0;i< n;i++)
    	for (j = 0; j < n; j++)
        	delete[] M[i][j];
    	delete[] M[i];
	delete[] M;
	
    cout<<res<<endl;
    
    }
    return 0;
}

