#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	string s; cin >> s;
	ll n = s.size();
	vector<ll> f(n);
	f[0] = s[0] - '0';
	for(ll i = 1; i < n; i++)
	{
		string tmp = "";
		f[i] = f[i-1];
		for(int j = i; j >= 0; j--)
		{
			tmp = s[j] + tmp;
			f[i] += stoll(tmp);
		}
	}
	cout << f[n-1];
}