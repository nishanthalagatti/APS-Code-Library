#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[]={'a','b','c'};
    int n=3;
    for(int i=0; i< (1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cout<<a[j];
            }

        }
        cout<<endl;
    }
}
