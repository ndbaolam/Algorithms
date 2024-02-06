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
	
	int n; cin >> n;
	vector<int> a(n + 1);
	REP(i, 1, n) cin >> a[i];

	stack<int> st;
	vector<int> ans;
	DREP(i, n, 1)
	{
		while(!st.empty() and st.top() <= a[i])
			st.pop();
		if(st.empty()) ans.push_back(-1);
		else ans.push_back(st.top());
		st.push(a[i]);
	}
	reverse(all(ans));
	for(int x : ans) cout << x << ' ';
}