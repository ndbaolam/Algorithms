#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

bool match(char o, char c)
{
	if(o == '(' and c == ')') return true;
	if(o == '[' and c == ']') return true;
	if(o == '{' and c == '}') return true;
	return false;
}

bool check(string s)
{
	stack<char> st;
	for(char c : s)
	{
		if(c == '(' or c == '[' or c == '{')
			st.push(c);
		else
		{
			if(st.empty()) return false;
			char top = st.top(); st.pop();
			if(!match(top, c)) return false;
		}
	}
	return st.empty();
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	string s; cin >> s;
	if(check(s)) cout << 1;
	else cout << 0;
}