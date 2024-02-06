#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= (int)b; ++i)
#define DREP(i,a,b) for(int i = (int)a; i >= b; --i)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
using ll = long long;

struct edge
{
	int u, v, c;
	edge (int _u, int _v, int _c): u(_u), v(_v), c(_c) {};
};

struct DSU
{
	vector<int> par, size;
	void init(int n)
	{
		par.resize(n + 5);
		size.resize(n + 5, 1);
		REP(i,1,n) par[i] = i;
	}
	int find(int v)
	{
		return (v == par[v]) ? v : par[v] = find(par[v]);
	}
	bool join(int a, int b)
	{
		a = find(a);
		b = find(b);
		if(a == b) return false;

		if(size[a] < size[b]) swap(a,b);
		par[b] = a;
		size[a] += size[b];
		return true;
	}
} dsu;

int n, m;
vector<edge> a;

void inp()
{
	cin >> n >> m;
	REP(i,1,m)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back({x, y, z});
	}
	dsu.init(n);	
}

void kruskal()
{
	vector<edge> mst;
	int total_weight = 0;
	sort(all(a), [](edge &x, edge &y){
		return x.c < y.c;
	});
	for(auto x : a)
	{
		if(!dsu.join(x.u, x.v)) continue;
		total_weight += x.c;
		mst.push_back(x);
	}
	if(mst.size() != n - 1) 
		cout << "Do thi khong lien thong" << endl;
	else
	{ 
		cout << "MST: " << total_weight << endl;
		for(auto x : mst)
			cout << x.u << ' ' << x.v << ' ' << x.c << endl;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	inp();
	kruskal();
}