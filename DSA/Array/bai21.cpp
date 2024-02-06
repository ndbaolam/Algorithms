#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n; cin >> n;
	map<ll,ll> mp;
	ll a[n];
	for(ll &i : a)
		cin >> i;
	for(ll i : a)
	{
		mp[i]++;
		if(mp[i]==2)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}