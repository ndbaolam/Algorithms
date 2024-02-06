#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e3 + 5;

int n, m;
ll a[N][N], d[N][N];

void read(){
	cin >> n >> m;
	REP(i, 1, n){
		REP(j, 1, m){
			cin >> a[i][j];
			d[i][j] = 1e9;
		}
	}
}

void solve(){
	d[1][1] = a[1][1];
	REP(i, 1, n){
		REP(j, 1, m){
			if(a[i][j] == 0) continue;
			if(i - 1 >= 1) d[i][j]  = min(d[i][j] , d[i - 1][j] + a[i][j]);
			if(j - 1 >= 1) d[i][j]  = min(d[i][j] , d[i][j - 1] + a[i][j]);
			if(i - 1 >= 1 && j - 1 >= 1) d[i][j]  = min(d[i][j] , d[i - 1][j - 1] + a[i][j]);
		}
	}
	if(d[n][m] == 1e9) cout << -1;
	else cout << d[n][m];
}

int main(){
	faster();
	read();
	solve();
}