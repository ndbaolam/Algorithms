#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
ll f[505][505];
int a[505][505];

int main()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			f[i][j] = a[i][j];
		}
	}

	ll res = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j])
				f[i][j] = min({f[i][j-1], f[i-1][j], f[i-1][j-1]}) + 1;
			res = max(res, f[i][j]);
		}
	}
	cout << res;
}