#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int n, ans;
vector<pii> a[100005];
bool visited[100005];
int last_node;
// {vertex, weight}

void read(){
	cin >> n;
	REP(i, 1, n - 1){
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
}

void dfs(int s, int distance){
	visited[s] = true;
	if(ans < distance){
		ans = distance;
		last_node = s;
	}
	for(auto [x, y] : a[s]){
		if(!visited[x]){
			dfs(x, distance + y);
		}
	}
}

int main(){
	faster();
	read();
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	dfs(last_node, 0);
	cout << ans;
}