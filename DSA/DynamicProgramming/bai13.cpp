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
	ll in[n], de[n];
	for(int i = 0; i < n; i++)
	{
		in[i] = a[i];
		for(int j = 0; j < i; j++)
			if(a[i] > a[j])
				in[i] = max(in[i], in[j] + a[i]);
	}

	for(int i  = n - 1; i >= 0; i--)
	{
		de[i] = a[i];
		for(int j = n - 1; j > i; j--)
			if(a[i] > a[j])
				de[i] = max(de[i], de[j] + a[i]);
	}

	ll res = 0;
	for(int i = 0; i < n; i++)
		res = max(res, in[i] + de[i] - a[i]);
	
	cout << res;
}