#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(ll a, ll b, ll n, ll m)
{
	ll s = (m/a)*(m/b);
	return s >= n;
}

int main()
{
	ll a, b, n; cin >> a >> b >> n;
	ll l=max(a,b); ll r=max(a,b)*n;
	ll ans;
	while(l<=r)
	{
		ll m = (l+r)/2;
		if(check(a,b,n,m))
		{
			ans=m;
			r=m-1;
		}
		else l=m+1;
	}
	cout << ans;
	return 0;
}