#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define pii pair<int,int>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, a[N], d[N], ans;

void sovle(){
	cin >> n;
	REP(i, 1, n) cin >> a[i];

	set<pii> s;
	//{value, index}
	//O(nlogn)
	REP(i, 1, n){
		d[i] = 1;
		auto it = s.lower_bound({a[i] - 1, 0});
		if(it != s.end() && it->first == a[i] - 1)
			d[i] = max(d[i], d[it->second] + 1);
		s.insert({a[i], i});
		ans = max(d[i], ans);
	}
	cout << ans << endl;
}

int main(){
	int t; cin >> t;
	while(t--)	{
		sovle();
	}
}