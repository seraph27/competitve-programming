#include<bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i;
	long long mn,mx,s;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		mn=1000000000000000000LL;
		mx=-1;
		s=0;
		for(i=0;i<n;i++)
		{
			s+=a[i];
			mn=min(mn,s/(i+1));
		}
		s=0;
		for(i=n-1;i>-1;i--)
		{
			s+=a[i];
			mx=max(mx,(s+n-i-1)/(n-i));
		}
		cout<<mx-mn<<'\n';
	}
	return 0;
}
