#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int v, n; cin >> n >> v;
	vector<int> w(n+1), c(n+1);
	for(int i = 1; i <= n; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) cin >> c[i];

	ll f[n+1][v+1];
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= v; j++)
		{
			if(i == 0 || j == 0)
				f[i][j] = 0;
			else
			{
				if(j - w[i] >= 0)
					f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + c[i]);
				else f[i][j] = f[i-1][j];
			}
		}
	}
	cout << f[n][v];
}