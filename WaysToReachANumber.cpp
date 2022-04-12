//Ways to reach a number using 3's,5's and 10's
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void combos(int x, int y, int z,int n);

int main()
{
    int x,y,z,n;
    cout<<"Enter x,y,z: ";
    cin>>x;
    cin>>y;
    cin>>z;
    cout<<"Enter n: ";
    cin>>n;
    combos(x,y,z,n);
}

void combos(int x,int y, int z, int n)
{
    int r[n+1];
    memset(r,0,sizeof(r));
    r[0]=1; // To reach 0 there is no way which is considered as 1 way.
    int i;

    for(i=x;i<=n;i++)
        r[i]=r[i]+r[i-x];
    for(i=y;i<=n;i++)
        r[i]=r[i]+r[i-y];
    for(i=z;i<=n;i++)
        r[i]=r[i]+r[i-z];
    cout<<"\n";
    for(i=0;i<=n;i++)
        cout<<r[i]<<" ";
    cout<<"\n";
}
