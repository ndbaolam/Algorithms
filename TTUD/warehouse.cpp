#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	int n, T, D; cin >> n >> T >> D;
	vector<int> a(n + 1), t(n + 1);
	REP(i, 1, n) cin >> a[i];
	REP(i, 1, n) cin >> t[i];

	ll f[n + 1][T + 1];
	memset(f, 0, sizeof(f));
	
	f[1][t[1]] = a[1];

	REP(i, 2, n)
	{
		REP(j, max(1, i - D), i - 1)
		{
			REP(k, 1, T)
			{
				if(k >= t[i])
					f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
				//else f[i][k] = max(f[i][k], f[j][k]);
			}
		}
	}
	ll ans = 0;
	REP(i, 1, n)
	{
		REP(j, 0, T)
		 ans = max(ans, f[i][j]);
	}
	cout << ans;
}
