#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int n, m;
int c[505][505];

void read()
{
	cin >> n >> m;
	REP(i, 1, n) REP(j, 1, m) cin >> c[i][j];
}

int max_area(int a[])
{
	stack<pii> st;
	int ans = 0;
	REP(i, 1, m)
	{
		int pos = i;
		while(!st.empty() and a[i] < st.top().second)
		{
			pos = st.top().first;
			int h = st.top().second;
			ans = max(ans, h * (i - pos));
			st.pop();
		}
		st.push({pos, a[i]});
	}
	while(!st.empty())
	{
		int pos = st.top().first;
		int h = st.top().second;
		ans = max(ans, h * (n - pos + 1));
		st.pop();
	}
	return ans;
}


int solve()
{
	int ans = 0;
	REP(i, 1, n)
	{
		REP(j, 1, m)
			c[i][j] = (c[i][j] == 0) ? 0 : c[i - 1][j] + 1;
		ans = max(ans, max_area(c[i]));
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
	
	read();
	cout << solve();
}