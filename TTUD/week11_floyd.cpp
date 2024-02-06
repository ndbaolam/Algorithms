#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> d;
vector<vector<int>> trace;
vector<int> path;

const int INF = 1e9;

void read(){
	cin >> n >> m;
	d.resize(n + 1, vector<int>(n + 1, INF));
	trace.resize(n + 1, vector<int>(n+1));
	REP(i, 1, m){
		int x, y, c; cin >> x >> y >> c;
		d[x][y] = c;
		trace[x][y] = x; //init trace
	}
}

void FloydWarsahll(){
	REP(i, 1, n) d[i][i] = 0;
	REP(k, 1, n){
		REP(i, 1, n){
			REP(j, 1, n){
				if(d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					trace[i][j] = trace[k][j];
				}
			}
		}
	}
}

void reverse_path(int u, int v){
	path.clear();
	while(v != u){
		path.push_back(v);
		v = trace[u][v];
	}
	path.push_back(u);
	reverse(all(path));
}

int main(){
	faster();
	read();
	FloydWarsahll();
	REP(i, 1, n){
		REP(j, 1, n)
			cout << d[i][j] << ' ';
		cout << endl;
	}
	reverse_path(2, 3);
	cout << "reverse_path: ";
	for(int x : path) cout << x << ' ';
}