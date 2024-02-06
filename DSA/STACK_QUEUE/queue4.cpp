#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

bool result(string s, int n)
{
	int sum = 0;
	DREP(i, s.size() - 1, 0)
		if(s[i] == '1')
			sum += 1 << i;
	return sum <= n;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	vector<string> v;
	int n; cin >> n;
	queue<string> q;
	q.push("1");
	while(!q.empty())
	{
		string t = q.front(); q.pop();
		if(!result(t + "0", n)) break;
		v.push_back(t);
		q.push(t + "0");
		q.push(t + "1");
	}
	if(n & 1)  v.pop_back();
	for(auto x : v)
		cout << x << ' ';
}