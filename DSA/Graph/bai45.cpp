#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

vector<pii> a[1005];
bool visited[1005];
int n, m;

int dijkstra(int s, int t)
{
	if(s == t) return 0;
	vector<ll> d(n + 5, 1e6);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	//{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty())
	{
		pii top = Q.top(); Q.pop();
		int u = top.se, k = top.fi;
		if(k > d[u]) continue;
		//visited[u] = true;
		for(auto i : a[u])
		{
			int v = i.fi, w = i.se;
			if(d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	return d[t];
}

void inp()
{
	cin >> n >> m;
	REP(i,1,m) 
	{
		int x, y, w; cin >> x >> y >> w;
		a[x].push_back({y, w});
		a[y].push_back({x,w});
	}
	int q; cin >> q;
	while(q--)
	{
		int s, t; cin >> s >> t;
		cout << dijkstra(s,t) << endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	inp();
}