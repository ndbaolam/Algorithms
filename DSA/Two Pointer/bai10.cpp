#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n, k; cin >> n >> k;
	set<ll> a;
	for(int i=0;i<n;i++)
	{
		ll x; cin >> x;
		a.insert(x);
	}

	for(ll i : a)
	{
		if(a.count(k-i))
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}