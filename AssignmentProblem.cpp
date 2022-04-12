#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n=2;
int cost[2][2];

int check_set_bit(int x)
{
    if(x & 1)
    {
        return 1;
    }
    return 0;
}

int count_bits(int x)
{
    int count=0;
    while(x)
    {
        if(x & 1)
            count++;
        x = x>>1;
    }
    return count;
}

void assignment()
{
    int size=pow(2,n);
    int dp[size],x,j;
    for(int i=0;i<size;i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0]=0;

    for(int mask=0;mask<size;mask++)
    {
        int temp=mask;
        x=count_bits(mask);
        for(j=0;j<n;j++)
        {

            //if(!(check_set_bit(temp>>j)))
            //{
                dp[mask | (1<<j)] = min(dp[mask | (1<<j)], dp[mask]+cost[x][j]);
            //}
        }
    }
    cout<<"Optimal Solution "<<dp[size-1];
}

main()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }

    assignment();
}
