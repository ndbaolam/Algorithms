#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = unsigned long long;

const ll mod = 1e9 + 7;

ll binpow(ll a, ll b)
{
	if(b == 0) return 1;
	ll x = binpow(a,b/2);
	if(b&1) 
		return (x % mod) * (x % mod) * (a % mod) % mod;
	else 
		return (x % mod) * (x % mod) % mod;
}

int main()
{
	int n; cin >> n;
	if(n*(n+1) % 4 != 0) 
	{
		cout << 0 << endl;
		return 0;
	}

	ll sum = (n+1)*n/4;
	vector<ll> f(sum + 1, 0);
	// f[i] so cach tao ra tong i
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = sum; j >= i; j--)
		{
			f[j] += f[j - i];
			f[j] %= mod;
		}
	}
	cout << (f[sum] % mod) * (binpow(2, mod-2) % mod) % mod<< endl;
}