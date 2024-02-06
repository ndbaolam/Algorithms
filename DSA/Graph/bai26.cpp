#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
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
int n, m;

void inp()
{
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void DFS(int v)
{
	visited[v] = true;
	for(int x : a[v])
		if(!visited[x]) DFS(x);
}

int main()
{
	inp();
	vector<int> res;
	REP(i,1,n)
	{
		sort(all(a[i]));
		if(!visited[i])
		{
			res.push_back(i);
			DFS(i);
		}
	}
	cout << res.size() - 1 << endl;
	REP(i,1,res.size()-1)
		cout << res[i-1] << ' ' << res[i] << endl;
}