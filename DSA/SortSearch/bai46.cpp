#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int a[],int n, int k, ll m)
{
	int cnt=0;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum > m)
		{
			cnt++;
			sum=a[i];
		}
	}
	++cnt;
	return cnt<=k;
}

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	ll r=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		r+=a[i];
	}
	ll l = *max_element(a,a+n);
	ll ans=-1;
	while(l<=r)
	{
		ll m=(l+r)/2;
		if(check(a,n,k,m))
		{
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	cout << ans;
	return 0;
}