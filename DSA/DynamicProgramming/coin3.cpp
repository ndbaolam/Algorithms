#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
vector<ll> f;

int main()
{
	int n, s; cin >> n >> s;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	f.resize(s + 1);
	//f[i] so cach doi i$
	f[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= s; j++)
		{
			if(j >= a[i])
				f[j] += f[j - a[i]];
			f[j] %= mod;
		}
	}
	cout << f[s];
}