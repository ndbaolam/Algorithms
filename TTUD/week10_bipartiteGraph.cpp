#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

vector<int> a[100005];
int state[100005];
int n, m;

void read(){
	cin >> n >> m;
	memset(state, -1, sizeof(state));
	REP(i, 1, m){
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

bool checkBipartiteGraph(int s){
	state[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(int x : a[top]){
			if(state[x] == -1){
				state[x] = !state[top];
				q.push(x);
			}
			else if(state[x] == state[top])
				return false;
		}
	}
	return true;
}

int main()
{
	faster();
	read();
	if(checkBipartiteGraph(1)) cout << 1;
	else cout << 0;
}