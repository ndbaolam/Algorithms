#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	vector<ll> a(n);
	for(ll &x : a) cin >> x;
	vector<ll> f(n);
	for(int i = 0; i < n; i++)
	{
		ll tmp = a[i];
		for(int j = 0; j < i; j++)
		{
			if(a[i] > a[j])
				tmp = max(tmp, f[j] + a[i]);
		}
		f[i] = tmp;
	}
	cout << *max_element(all(f));
}