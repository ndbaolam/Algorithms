#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;
int n, m, timer, bridge;
vector<int> a[N];
int low[N], num[N];

void read(){
	cin >> n;
	while(--n){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cin >> m;
	while(m--){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void dfs(int u, int par){
	low[u] = num[u] = ++timer;
	for(int v : a[u]){
		if(v == par) continue;
		if(!num[v]){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(num[u] < low[v]) ++bridge;
		}
		else low[u] = min(low[u], num[v]);
	}
}

int main(){
	faster();
	read();
	dfs(1, -1);
	cout << bridge;
}