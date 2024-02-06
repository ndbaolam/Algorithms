#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

int parentheses(string s)
{
	stack<char> a;
	int cnt = 0;
	for(char c : s)
	{
		if(c == '(') a.push(c);
		else
		{
			if(a.empty()) ++cnt;
			else a.pop();
		}
	}
	if(a.empty()) return cnt;
	else return a.size() + cnt;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	string s; cin >> s;
	cout << parentheses(s);
}