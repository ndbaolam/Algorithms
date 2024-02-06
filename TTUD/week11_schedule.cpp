#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int n, m;
int d[10004];
vector<int> a[10005];
int inDegree[10005];
int dp[10005];

void read(){
	cin >> n >> m;
	REP(i, 1, n) cin >> d[i];
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		inDegree[y]++;
	}
}

int topo(){
	queue<int> q;
	REP(i, 1, n) {
		if(!inDegree[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		dp[u] += d[u];
		for(int x : a[u]){
			dp[x] = max(dp[x], dp[u]);
			inDegree[x]--;
			if(!inDegree[x])
				q.push(x);
		}
	}
	return *max_element(dp + 1, dp + n + 1);
}

int main(){
	faster();
	read();
	cout << topo();
}