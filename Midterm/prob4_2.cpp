
#include <bits/stdc++.h>
#define BIT(x, i) (1 & ((x) >> (i)))
#define MASK(x) (1LL << (x))

using namespace std;
const int N = 13;
const long long INF = (int)1e9;

int n, m, k, q;
int ban[N];
int d[N];
int c[N][N];
int sum[(1<<N)], f[(1<<N)][N], cost[(1<<N)], dp[N][(1<<N)];

void read(){
	cin >> n >> k >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			cin >> c[i][j];
		}
	}
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		ban[u] |= (1 << v);
		ban[v] |= (1 << u);
	}

	memset(f, 0x3f, sizeof(f));
	memset(cost, 0x3f, sizeof(cost));
	memset(dp, 0x3f, sizeof(dp));
}

void solve() {
	for(int mask = 0; mask < (1<<n); ++mask) {
		for(int i = 0; i < n; ++i) {
			if(BIT(mask, i)) {
				sum[mask] += d[i+1];
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		if(d[i + 1] > q) {
			continue;
		}
		f[(1<<i)][i] = c[0][i+1];
	}
	for(int mask = 0; mask < (1<<n); ++mask) {
		if(sum[mask] > q) {
			continue;
		}
		for(int i = 0; i < n; ++i) {
			if(BIT(mask, i)) {
				for(int j = 0; j < n; ++j) {
					if(!BIT(mask, j)) {
						if((ban[j] & mask) > 0) {
							continue;
						}
						f[mask | (1<<j)][j] = min(f[mask | (1<<j)][j], f[mask][i] + c[i+1][j+1]);
					}
				}
			}
		}
	}

	for(int mask = 0; mask < (1<<n); ++mask) {
		for(int i = 0; i < n; ++i) {
			if(BIT(mask, i)) {
				cost[mask] = min(cost[mask], f[mask][i] + c[i+1][0]);
			}
		}
	}

	dp[0][0] = 0;
	for(int i = 1; i <= k; ++i) {
		for(int mask = 0; mask < (1<<n); ++mask) {
			dp[i][mask] = dp[i-1][mask];
			for(int submask = mask; submask > 0; submask = (submask - 1) & mask) {
				dp[i][mask] = min(dp[i][mask], dp[i-1][mask ^ submask] + cost[submask]);
			}
		}
	}

	if(dp[k][(1<<n)-1] >= INF) {
		cout << -1;
	} else {
		cout << dp[k][(1<<n)-1];
	}
}

int main()
{
	read();
    solve();
    return 0;
}
