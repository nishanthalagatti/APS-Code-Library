#include<iostream>
using namespace std;

void permutations(int num[500],int n)
{
    int i,j,k,temp;
    for(j=1;j<=n;j++){
        for(i=0;i<n-1;i++){
            temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;

            for(k=0;k<n;k++)
                cout<<num[k]<<" ";
            cout<<"\n";
        }
    }

}

int main()
{
    int n,num[500];
    cout<<"Enter n: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    permutations(num,n);
}
