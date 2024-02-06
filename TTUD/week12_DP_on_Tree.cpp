#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

vector<int> a[N]; //list of adjacent nodes to v
vector<int> c[N]; // children of v by dfs
int w[N];//w[v]: weight of node v
int p[N];//p[v]: parent of v on rooted tree
int f1[N]; //max total weight of IS on tree rooted at v (contain v)
int f0[N]; //max total weight of IS on tree rooted at v (not contain v)
int f[N]; //max total weight of IS on tree rooted at v
bool visited[N];
int root, n;
int d[N]; //d[v]: number of children of v
int ans;

void read(){
	cin >> n;
	REP(i, 1, n) cin >> w[i];
	REP(i, 1, n - 1){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void dfs(int u){
	visited[u] = true;
	for(int x : a[u]){
		if(!visited[x]){
			p[x] = u; d[u]++;
			c[u].push_back(x);
			dfs(x);
		}
	}
}

void solve(){
	queue<int> Q;
	REP(v, 1, n){
		f1[v] = w[v];
		if(d[v] == 0)//leaf
			Q.push(v);
	}
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		f[v] = max(f1[v], f0[v]);
		int pv = p[v]; 
		f0[pv] += f[v];
		f1[pv] += f0[v];
		d[pv]--;
		if(d[pv] == 0) Q.push(pv);
	}
	ans = f[root];
}

void init(){
	root = 1;
	memset(p, -1, sizeof(p));
	dfs(root);
}

int main(){
	faster();
	read();
	init();
	solve();
	cout << ans << endl;
}