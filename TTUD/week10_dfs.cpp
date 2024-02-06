#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

vector<int> a[10005];
int n, m;
bool visited[10005];

void read(){
	cin >> n >> m;
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void dfs(int s){
	cout << s << ' ';
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
	dfs(1);
}