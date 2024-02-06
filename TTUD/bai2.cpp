#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int d[2005][2005];

int sovle()
{
	int n, s; cin >> n >> s; 
	vector<int> a(n + 1);
	REP(i, 1, n) cin >> a[i];
	memset(d, 0, sizeof(d));

	int ans = 0;
	REP(i, 1, n)
	{
		REP(j, 1, s)
		{
			d[i][j] = (j >= a[i]) ? max({d[i - 1][j], d[i - 1][j - a[i]] + a[i], d[i][j - a[i]] + a[i]}) : d[i - 1][j];
			ans = max(ans, d[i][j]);
		}
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();

	int t; cin >> t;
	while(t--)	
	{
		cout << sovle() << endl;
	}
}