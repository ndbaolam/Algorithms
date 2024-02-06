#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const int N = 18;

int n, c[N][N];
int dp[1 << N][N];
vector<int> res;
// thanh pho u co trang thai la mask

int solve(int mask, int u)
{
	if(dp[mask][u] != -1)
		return dp[mask][u];
	if(mask == (1 << n) - 1)
		return 0;
	int ans = INT_MAX;
	REP(v, 0, n-1)
	{
		if(mask & (1 << v)) continue;
		int new_mask = mask | (1 << v);
		if(ans > solve(new_mask, v) + c[u][v])
		{
			ans = solve(new_mask, v) + c[u][v];
			res.push_back(v);
		}
	}
	return dp[mask][u] = ans;
}

int main()
{
	cin >> n;
	REP(i,0,n-1)
		REP(j,0,n-1) cin >> c[i][j];	
	int ans = INT_MAX;
	REP(u,0,n-1)
	{
		memset(dp, -1, sizeof(dp));
		int cur_ans = solve(1 << u, u);
		ans = min(ans, cur_ans);
	}
	cout << ans << endl;
}