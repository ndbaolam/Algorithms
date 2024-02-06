#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 5005;
int n, m;
int c[N], d[N];
vector<int> a[N], g[N];
int w[N][N];
bool visited[N]; 
int disc[N];
//disc[i]: distance from s to v

void read(){
	cin >> n >> m;
	REP(i, 1, n)
		cin >> c[i] >> d[i];
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void buildGraph(int s){
	queue<int> Q;
	Q.push(s);
	visited[s] = true;
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		w[s][v] = c[s];
		for(int u : a[v]){
			if(!visited[u] && disc[v] < d[s]){
				visited[u] = true;
				disc[u] = disc[v] + 1;
				Q.push(u);
				g[s].push_back(u);
			}
		}
	}
}

int dijkstra(int s, int t){
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	vector<int> f(n + 1, 1e9);
	f[s] = 0;
	Q.push({0, s});
	while(!Q.empty()){
		int u = Q.top().second; Q.pop();
		if(u == t) return f[u];
		for(int v : g[u]){
			if(f[v] > f[u] + w[u][v]){
				f[v] = f[u] + w[u][v];
				Q.push({f[v], v});
			}
		}
	}
	return -1;
}

int main(){
	faster();
	read();
	REP(i, 1, n){
		memset(visited, false, sizeof(visited));
		memset(disc, 0, sizeof(disc));
		buildGraph(i);
	}
	cout << dijkstra(1, n) << endl;
}