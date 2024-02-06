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
	
	string s; cin >> s;
	vector<string> v;
	DREP(i, s.size() - 1, 0)	
	{
		if(isalpha(s[i]))
			v.push_back(string(1, s[i]));
		else
		{
			string t1 = v.back(); v.pop_back();
			string t2 = v.back(); v.pop_back();
			string tmp = t1 + t2 + s[i];
			v.push_back(tmp);
		}
	}
	for(string x : v)
		cout << x;
}