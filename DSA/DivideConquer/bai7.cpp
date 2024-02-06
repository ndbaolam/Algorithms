#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int &x : a) cin >> x;
	sort(all(a));
	int ans = 0;
	for(int x : a)
	{
		if(x <= k)
			ans = max(ans,x);
	}
	if(ans==0) cout << -1;
	else cout << ans;
}