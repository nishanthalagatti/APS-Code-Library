#include<bits/stdc++.h>
using namespace std;

int binaryexponentiation(int a,int b)
{
    int res=1;
    while(b>0)
    {
        if(b%2)
        {
            res=res*a;
        }
        a=a*a;
        b/=2;
    }
    return res;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<binaryexponentiation(a,b)<<endl;
}
