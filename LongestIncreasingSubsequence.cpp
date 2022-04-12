//Find length of longest increasing subsequence in an array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findLIS(int n, int a[])
{
    int LIS[n];
    int i,j,maxlen=1;
    for(i=0;i<n;i++)
    {
        LIS[i]=1;
    }

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j] && LIS[j]+1>LIS[i])
                LIS[i]=LIS[j]+1;
            if(maxlen<LIS[i])
                maxlen=LIS[i];
        }
    }
    cout<<endl<<"Length of LIS: "<<maxlen;

}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int a[n];
    cout<<"Enter array: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    findLIS(n,a);
}
