#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int a[N];

int main(){
	int n, m; cin >> n >> m;	
	REP(i, 1, n) cin >> a[i];
	int ans = 0, sum  = 0, l = 1;
	REP(r, 1, n){
		sum += a[r];
		while(sum > m) sum -= a[l++];
		ans = max(ans, r - l + 1);
	}
	cout << ans;
}