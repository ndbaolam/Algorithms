#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

struct edge{
	int u, v, c;
	edge(int _u, int _v, int _c){
		u = _u;
		v = _v;
		c = _c;
	}
};

struct DSU{
	vector<int> par, size;
	void init(int n){
		par.resize(n + 5);
		size.resize(n + 5, 1);
		REP(i, 1, n) par[i] = i;
	}
	int find(int v){
		return (v == par[v]) ? v : par[v] = find(par[v]);
	}
	void join(int a, int b){
		a = find(a);
		b = find(b);
		if(a == b) return;
		if(size[a] < size[b]) swap(a, b);
		par[b] = a;
		size[a] += size[b];
	}
} dsu;

int n, m;
vector<edge> a;

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y, z;
		cin >> x >> y >> z;
		a.push_back({x, y, z});
	}
	dsu.init(n);
}

int kruskal(){
	vector<edge> mst;
	int total_weight = 0;
	sort(all(a), [](edge &x, edge &y){
		return x.c < y.c;
	});
	for(auto x : a){
		if(dsu.find(x.u) == dsu.find(x.v)) continue;
		total_weight += x.c;
		mst.push_back(x);
		dsu.join(x.u, x.v);
	}
	return total_weight;
}

int main(){
	faster();
	read();
	cout << kruskal();
}