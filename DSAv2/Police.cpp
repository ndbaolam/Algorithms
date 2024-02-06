#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m, Q, timer;
vector<int> a[N];
int low[N], num[N];
bool AP[N];
map<pii, bool> mp;

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cin >> Q;
}

void dfs(int u, int par){
	low[u] = num[u] = ++timer;
	int child = 0;
	for(int v : a[u]){
		if(v == par) continue;
		if(!num[v]){
			dfs(v, u); ++child;
			low[u] = min(low[u], low[v]);
			if(num[u] < low[v]) mp[{u, v}] = mp[{v, u}] = true;
			if(par != -1 && num[u] <= low[v]) AP[u] = true;
		}
		else low[u] = min(low[u], num[v]);
	}
	if(par == -1 and child > 1) AP[u] = true;
}

int main(){
	faster();
	read();
	dfs(1, -1);
	while(Q--){
		int x; cin >> x;
		if(x == 1){
			int a, b; cin >> a >> b;
			if(mp[{a, b}]) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
		else{
			int a; cin >> a;
			if(AP[a]) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
}