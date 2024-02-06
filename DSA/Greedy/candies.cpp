#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n], b[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i-1]<a[i])
			b[i]=b[i-1]+1;
	}
	for(int i=n-2;i>=0;i--)
	{
		int tmp=b[i];
		if(a[i]>a[i+1])
			tmp=b[i+1]+1;
		b[i]=max(b[i],tmp);
	}
	ll ans=0;
	for(int i : b)
		ans+=1ll*i;
	cout << ans;
}
