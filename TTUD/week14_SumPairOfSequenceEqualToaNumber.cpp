#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
map<int, int> mp;
int a[N];

int main(){
	int n, m, ans = 0; cin >> n >> m;	
	REP(i, 1, n) {
		cin >> a[i];
		if(mp[m - a[i]]) ++ans;
		mp[a[i]]++;
	}
	cout << ans;
}