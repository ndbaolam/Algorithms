#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

ll mod = 1e9+7;

ll binpow(ll n, ll k)
{
	if(k==0) return 1;
	ll x = binpow(n,k/2);
	if(k&1) return (x%mod * x%mod * n%mod) % mod;
	else return (x%mod * x%mod) % mod;
}

int main()
{
	ll n, k; cin >> n >> k;
	cout << binpow(n,k);
}