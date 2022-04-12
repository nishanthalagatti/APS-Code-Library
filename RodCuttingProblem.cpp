#include <iostream>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

void rodCutting(int n)
{
    int results[n+1];
    memset(results,0,sizeof(results));
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
        {
            results[i]=max(results[i], max(j*(i-j), j*results[i-j]));
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<results[i]<<" ";
    }
}

int main()
{
    rodCutting(10);
}
