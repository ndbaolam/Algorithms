#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

bool check(string s)
{
	stack<char> a, b, c;
	REP(i, 0, s.size() - 1)
	{
		if(s[i] == '(') a.push(s[i]);
		else if(s[i] == '[') b.push(s[i]);
		else if(s[i] == '{') c.push(s[i]);

		if(s[i] == ')')
		{
			if(a.empty()) return false;
			else a.pop();
		}
		else if(s[i] == ']')
		{
			if(b.empty()) return false;
			else b.pop();
		}
		else if(s[i] == '}')
		{
			if(c.empty()) return false;
			else c.pop();
		}
	}
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	string s; cin >> s;
	if(check(s)) cout << "YES";
	else cout << "NO";
}