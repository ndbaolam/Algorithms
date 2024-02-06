#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int bfs(int s, int t)
{
	queue<pii> q;
	q.push({s, 0});
	set<int> used;
	used.insert(s);
	while(!q.empty())
	{
		pii top = q.front(); q.pop();
		int n = top.first, m = top.second;

		if(n == t) return m;

		if(n > 1 and !used.count(n - 1))
		{
			q.push({n - 1, m + 1});
			used.insert(n -1 );
		}
		REP(i, 2, sqrt(n))
		{
			if(n % i == 0)
			{
				int v = max(n / i, i);
				if(!used.count(v))
				{
					q.push({v, m + 1});
					used.insert(v);
				}
			}
		}
	}
	return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	int n; cin >> n;
	while(n--)
	{
		int s; cin >> s;
		cout << bfs(s, 1) << endl;
	}
}