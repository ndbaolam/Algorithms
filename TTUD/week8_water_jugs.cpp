#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

// chuyen trang thai => queue

bool used[1005][1005];
int d[1005][1005];
vector<pii> ans[9];

int solve(int a, int b, int c)
{
	queue<pii> q;
	q.push({0,0});
	used[0][0] = true;
	REP(i, 1, 8) ans[i].push_back({0, 0});
	while(!q.empty())
	{
		pii top = q.front(); q.pop();
		int x = top.first, y = top.second;
		if(x == c or y == c) 
			return d[x][y];

		if(!used[a][y])
		{
			used[a][y] = true;
			q.push({a, y});
			d[a][y] = d[x][y] + 1;
			ans[1].push_back({a, y});
		}
		if(!used[x][b])
		{
			used[x][b] = true;
			q.push({x, b});
			d[x][b] = d[x][y] + 1;
			ans[2].push_back({x, b});
		}
		if(!used[0][y])
		{
			used[0][y] = true;
			q.push({0, y});
			d[0][y] = d[x][y] + 1;
			ans[3].push_back({0, y});
		}
		if(!used[x][0])
		{
			used[x][0] = true;
			q.push({x, 0});
			d[x][0] = d[x][y] + 1;
			ans[4].push_back({x, 0});
		}
		if(x + y >= b and !used[x + y - b][b])
		{
			used[x + y - b][b] = true;
			q.push({x + y - b, b});
			d[x + y - b][b] = d[x][y] + 1;
			ans[5].push_back({x + y - b, b});
		}
		else if(x + y < b and !used[0][x + y])
		{
			used[0][x + y] = true;
			q.push({0, x + y});
			d[0][x + y] = d[x][y] + 1;
			ans[6].push_back({0, x + y});
		}
		if(x + y >= a and !used[a][x + y - a])
		{
			used[a][x + y - a] = true;
			q.push({a, x + y - a});
			d[a][x + y - a] = d[x][y] + 1;
			ans[7].push_back({a, x + y - a});
		}
		else if(x + y < a and !used[x + y][0])
		{
			used[x + y][0] = true;
			q.push({x + y, 0});
			d[x + y][0] = d[x][y] + 1;
			ans[8].push_back({x + y, 0});
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
	
	int a, b, c; cin >> a >> b >> c;
	cout << solve(a, b, c) << endl;

	REP(i, 1, 8)
	{
		for(auto [x, y] : ans[i])
			cout << "(" << x << ", " << y << ")" << ' ';
		cout << endl;
	}
}