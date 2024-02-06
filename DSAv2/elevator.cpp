#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 25;
const ll mod = 1e9 + 7;

int n, k;
vector<int> w(N);
pii dp[1 << N];
// dp[mask]: so lan su dung thang may,
// khoi luong thang may hien tai
int main()
{
	cin >> n >> k;
	REP(i,0,n-1) cin >> w[i];
	REP(mask, 0, (1 << n)-1)
		dp[mask] = {1e6, 0};
	dp[0] = {1,0};
	REP(mask, 0, (1<<n)-1)
	{
		REP(i,0,n-1)
		{
			if(mask & (1 << i)) continue;
			int new_mask = mask | (1 << i);
			pii cur_mask = dp[mask];
			if(dp[mask].se + w[i] <= k) 
				cur_mask.se += w[i];
			else
			{ 
				cur_mask.fi++;
				cur_mask.se = w[i];
			}
			dp[new_mask] = min(dp[new_mask], cur_mask);
		}
	}
	cout << dp[(1 << n) - 1].fi << endl;
}