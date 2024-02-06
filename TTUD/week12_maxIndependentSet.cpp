#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

set<int> s[1005];
int n, ans, w[1005], d[1005];
vector<int> a;

void read(){
	cin >> n;
	REP(i, 1, n) cin >> w[i];
	REP(i, 1, n - 1){
		int x, y; cin >> x >> y;
		s[x].insert(y);
		s[y].insert(x);
	}
}

bool check(int i){
	for(int x : a){
		if(s[x].count(i)) return false;
	}
	return true;
}

void back(int k, int sum, int pos){
	ans = max(ans, sum);
	REP(i, pos, n){
		if(check(i)){
			a.push_back(i);
			back(k + 1, sum + w[i], i + 1);
			a.pop_back();
		}
	}
}

int main(){
	faster();
	read();
	back(1, 0, 1);
	cout << ans;
}