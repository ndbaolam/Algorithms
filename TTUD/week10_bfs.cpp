#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
vector<int> a[maxn];
bool visited[maxn];
int n, m;

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		//a[y].push_back(x);
	}
	REP(i, 1, m){
		sort(all(a[i]));
	}
}

void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int x : a[top]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
			}
		}
	}
}

void dfs(int s){
	visited[s] = true;
	for(int x : a[s]){
		if(!visited[x])
			dfs(x);
	}
}

int main()
{
	faster();
	read();
	int cnt = 0;
	REP(i, 1, n){
		if(!visited[i]){
			dfs(i);
			++cnt;
		}
	}
	cout << cnt;
}