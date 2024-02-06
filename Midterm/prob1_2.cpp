#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int main(){
	int n; cin >> n;
	int ans = 0;
	map<int, int> mp;
	int a[n + 5];
	REP(i, 1, n){
		cin >> a[i];
		ans += mp[a[i] - 1];
		ans += mp[a[i] + 1];
		mp[a[i]]++;
	}
	cout << ans;
}