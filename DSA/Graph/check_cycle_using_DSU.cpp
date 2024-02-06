#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

int n, m;
vector<int> a[1005];

struct DSU{
	vector<int> parent, size;
	void init(int n)
	{
		parent.resize(n + 5);
		size.resize(n + 5, 1);
		REP(i,1,n) parent[i] = i;
	}
	int find(int v)
	{
		return (v == parent[v]) ? v : parent[v] = find(parent[v]);
	}
	void join(int a, int b)
	{
		a = find(a);
		b = find(b);
		if(a == b) return;
		if(size[b] > size[a]) swap(a,b);
		parent[b] = a;
		size[a] += size[b];
	}
} dsu;

void inp()
{
	cin >> n >> m;
	dsu.init(n);
	int check = 0;
	REP(i,1,m)
	{
		int x, y; cin >> x >> y;
		if(dsu.find(x) == dsu.find(y)) check = 1;
		else dsu.join(x, y);
	}
	cout << check << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	inp();
}