#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 100;

int n, M; //number of clients
int K; //number of trucks
int Q; //capacity of a truck
int d[N]; //d[i] is demand of client i
int x[N];//next point of point v
int y[N];//the first client on route k
int c[N][N], f[N][N];//c[i][j] is the distance from i tp j
bool visited[N];
int load[N]; //load[k] is the total demand of clients on route k
int segment;
int ans = 1e9, sum;
int nbRoute;

void read(){
	cin >> n >> K >> Q;
	REP(i, 1, n) cin >> d[i];
	REP(i, 0, n) REP(j, 0, n) cin >> c[i][j];
}

bool checkX(int v, int k){
	if(v > 0 && visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void TryX(int u, int k){
	for(int v = 0; v <= n; v++){
		if(checkX(v, k)){

			x[u] = v;
			sum += c[x[u - 1]][x[u]];
			visited[v] = true;
			load[k] += d[v];
			segment += 1;

			if(v == 0){
				if(k == K){
					if(segment == n + K)
						ans = min(ans, sum);
				}
				else TryX(y[k + 1], k + 1);
			}
			else TryX(v, k);

			visited[v] = false;
			load[k] -= d[v];
			segment -= 1;
			sum -= c[x[u - 1]][x[u]];
		}
	}
}

bool checkY(int v, int k){
	if(v == 0) return true;
	if(load[k] + d[v] > Q) return false;
	return !visited[v];
}

void TryY(int k){
	for(int v = y[k - 1] + 1; v <= n; v++){
		if(checkY(v, k)){		

			load[k] += d[v];
			y[k] = v;
			sum += c[y[k - 1]][y[k]];
			visited[v] = true;
			segment += 1;

			if(k == K) {
				nbRoute = segment;
				TryX(y[1], 1);
			}
			else TryY(k + 1);

			load[k] -= d[v];
			visited[v] = false;
			segment -= 1;
			sum -= c[y[k - 1]][y[k]];
		}
	}
}

int main(){
	faster();
	read();
	TryY(1);
	cout << ans;
}