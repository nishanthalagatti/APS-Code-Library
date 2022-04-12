#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void subsetSum(int ,int , int []);

int main()
{
    int i,items;
    cout<<"Enter no of items: ";
    cin>>items;
    int a[items];
    cout<<"Enter "<<items<<" items: ";
    for(i=0;i<items;i++){
        cin>>a[i];
    }
    int sum;
    cout<<"Enter sum: ";
    cin>>sum;
    subsetSum(items,sum,a);

}

void subsetSum(int items, int sum,int a[])
{
    int ss[items+1][sum+1];
    int i,j;
    for(i=0;i<=items;i++){
        ss[i][0]=true;//can form sum of 0 no matter no. of items given
    }
    for(i=1;i<=sum;i++){
        ss[0][i]=false;//cannot form any sum with no items
    }

    for(i=1;i<=items;i++){
        for(j=1;j<=sum;j++){
            if(ss[i-1][j]) //previous solution exists
                ss[i][j]=true;
            else{
                if(a[i-1]>j)
                    ss[i][j]=false;
                else
                    ss[i][j]=ss[i-1][j-a[i-1]];
            }
        }
    }
    for(i=0;i<=items;i++)
    {
        for(j=0;j<=sum;j++)
        {
            cout<<ss[i][j]<<" ";
        }
        cout<<"\n";
    }
}
