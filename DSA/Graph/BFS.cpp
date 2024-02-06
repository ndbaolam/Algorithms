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
int parent[N];
bool visited[N];
int n, m, s;

void inp()
{
	memset(visited, false, sizeof(visited));
	cin >> n >> m >> s;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << ' ';
		for(int y : a[x])
		{
			if(!visited[y])
			{
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main()
{
	inp();
	REP(i,1,n)
		sort(all(a[i]));
	BFS(s);
}