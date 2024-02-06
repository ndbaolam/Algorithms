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

	string s;
	vector<string> v;
	while(getline(cin, s))	
	{
		stringstream S(s);
		string tmp;
		while(S >> tmp) v.push_back(tmp);
	}
	reverse(all(v));
	for(string x : v) cout << x << ' ';
}