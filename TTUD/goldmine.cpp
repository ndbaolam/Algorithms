#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	int n, l, r; cin >> n >> l >> r;
	vector<int> a(n + 1), f(n + 1);
	REP(i, 1, n) cin >> a[i];
	deque<int> d;
	//luu tru chi so cac ung cu vien j
	int ans = 0;
	REP(i, 1, n)
	{
		while(!d.empty() and d.front() < i - r) d.pop_front();
		if(i - l >= 1)
		{
			while(!d.empty() and f[d.back()] < f[i - l]) d.pop_back();
			d.push_back(i - l);
		}
		f[i] = a[i] + (d.empty() ? 0 : f[d.front()]);
		ans = max(ans, f[i]);
	}
	cout << ans;
}