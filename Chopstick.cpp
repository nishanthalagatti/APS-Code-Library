#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<int>l(n);
    for(int i=0;i<n;i++)
        cin>>l[i];
    sort(l.begin(),l.end());
    int c = 0;
	int i = 1;
	while(i<n){
	    if(l[i]-l[i-1]<=d){
	        c++;
	        i += 2;
	    }else
	        i++;
	}
	cout<<c<<endl;
}
