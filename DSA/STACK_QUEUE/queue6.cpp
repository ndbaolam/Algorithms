#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long double;

vector<ll> res;

void generate()
{
	queue<ll> q;
	q.push(1);
	while(!q.empty())
	{
		ll top = q.front(); q.pop();
		if(top > pow(2, 63)) break;
		res.push_back(top);
		q.push(top * 10);
		q.push(top * 10 + 1);
	}
}

int count(int x)
{
	int l = 0, r = res.size() - 1, m = -1;
	while(l <= r)
	{
		m = (l + r) >> 1;
		if(res[m] < x)
			l = m + 1;
		else r = m - 1;
	}
	return m;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	generate();
	int n; cin >> n;
	while(n--)
	{
		int x; cin >> x;
		cout << count(x) + 1 << endl;
	}
}