#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll binpow(ll n, ll m)
{
	if(m == 0) return 1;
	ll x = binpow(n,m/2);
	if(m&1) return (x%mod * x%mod * n%mod) % mod;
	else return (x%mod * x%mod) % mod;
}

int main()
{
	ll n, m; cin >> n >> m;
	cout << binpow(n, m);
}