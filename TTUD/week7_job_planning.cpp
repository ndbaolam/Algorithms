#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int n;
vector<pii> a;
bool used[10005];

void read()
{
	cin >> n; 
	REP(i, 1, n)
	{
		int x, y; cin >> x >> y;
		a.push_back({x, y});
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	read();
	sort(all(a), [](pii x, pii y){
		return x.second > y.second;
	});
	ll ans = 0;
	
	for(auto [x, y] : a)
	{
		DREP(i, x, 1)
		{
			if(!used[i])
			{
				used[i] = true;
				ans += 1ll * y;
				break;
			}
		}
	}
	cout << ans;
}