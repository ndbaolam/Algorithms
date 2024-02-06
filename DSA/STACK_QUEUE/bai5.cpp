#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

string solve(int x)
{
	queue<string> q;
	q.push("8");
	while(!q.empty())
	{
		string top = q.front(); q.pop();
		if(stoll(top) % x == 0) return top;
		q.push(top + "0");
		q.push(top + "8");
	}
	return "";
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	int n; cin >> n;
	while(n--)
	{
		int x; cin >> x;
		cout << solve(x) << endl;
	}
}