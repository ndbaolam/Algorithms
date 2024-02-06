#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	ll a[n];
	for(ll &i : a)
		cin >> i;
	sort(a,a+n);
	for(int i = 2; i < n; i++)
	{
		ll x = 1ll*a[i-2]*a[i-2];
		ll y = 1ll*a[i-1]*a[i-1];
		ll z = 1ll*a[i]*a[i];
		if(x+y==z)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}