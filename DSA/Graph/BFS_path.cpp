#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 1005;
const ll mod = 1e9 + 7;

vector<int> a[N];
bool visited[N];
int parent[N];
int n, m, s, t;

void inp()
{
	memset(visited, false, sizeof(visited));
	cin >> n >> m >> s >> t;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
	}
}

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	visited[s]= true;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int y : a[x])
		{
			if(!visited[y])
			{
				parent[y] = x;
				visited[y] = true;
				q.push(y);
			}
		}
	}
}

void path(int s, int t)
{
	BFS(s);
	if(!visited[t])
		cout << -1 << endl;
	else
	{
		vector<int> res;
		while(t != s)
		{
			res.push_back(t);
			t = parent[t];
		}
		res.push_back(s);
		reverse(all(res));
		for(int x : res)
			cout << x << ' ';
	}
}

int main()
{
	inp();
	REP(i,1,n)
		sort(all(a[i]));
	path(s,t);
}