#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int INF = 1e9;
int n, m, s, t;
vector<pii> a[maxn];
int parent[maxn];

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y, c; cin >> x >> y >> c;
		a[x].push_back({y,c});
	}
	cin >> s >> t;
}

int dijsktra(int s, int t){
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		pii top = Q.top(); Q.pop();
		int u = top.second;
		if(u == t) return d[u];
		for(auto [v, w] : a[u]){
			//duyet cac dinh ke voi dinh u
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				parent[v] = u; //truy vet
				Q.push({d[v], v});
			}
		}
	}
	return -1;
}

void tryvet(){
	vector<int> ans;
	while(s != t){
		ans.push_back(t);
		t = parent[t];
	}
	ans.push_back(s);
	reverse(all(ans));
	for(int x: ans)
		cout << x << ' ';
}

int main(){
	faster();
	read();
	cout << dijsktra(s, t) << endl;
}