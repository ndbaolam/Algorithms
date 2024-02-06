#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()

bool check(ll n, ll x, ll y, ll time)
{
	time -= min(x,y);
	ll cnt = (time/x) + (time/y);
	return cnt >= --n;
}

int main()
{
	ll n, x, y; cin >> n >> x >> y;
	ll time = -1;
	ll l=0;
	ll r=1ll*min(x,y)*n ;
	while(l<=r)
	{
		ll m = (l+r)/2;
		if(check(n,x,y,m))
		{
			time=m;
			r=m-1;
		}
		else l=m+1;
	}
	cout << time;
	return 0;
}