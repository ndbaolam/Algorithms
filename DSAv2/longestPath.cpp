#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, m, ans;
vector<int> a[N];

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
	}
}

void dfs(int u, int distance){
	ans = max(ans, distance);
	for(int v : a[u])
		dfs(v, distance + 1);
}

int main(){
	faster();
	read();
	REP(i, 1, n)
		dfs(i, 0);
	cout << ans;
}