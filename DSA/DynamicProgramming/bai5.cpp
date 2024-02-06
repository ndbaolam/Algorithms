#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n, k; cin >> n;
	k = 3;
	++n;
	ll f[n];
	for(ll &x : f) x = 0;
	f[n-1] = 1;
	for(int i = n-2; i >= 0; i--)	
	{
		for(int j = 1; j <= k; j++)
			if(i + j < n)
				f[i] += f[i+j];
		f[i] %= mod;
	}
	cout << f[0];
}