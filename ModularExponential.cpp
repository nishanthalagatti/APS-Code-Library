#include<bits/stdc++.h>
using namespace std;

int power(int x,int y,int p)  
{  
    int res=1; 
    x=x%p;
    if(x==0) 
    	return 0;
    while(y>0)  
    {
        if(y&1) 
        	res=(res*x)%p;
        y=y>>1; 
        x=(x*x)%p;  
    }
    return res;  
}  

int main() 
{
	//(x^y)%mod
	int x,y,mod;
	cin>>x>>y>>mod;
	cout<<power(x,y,mod);
    return 0;
}
