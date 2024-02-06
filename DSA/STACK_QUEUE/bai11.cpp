#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
using namespace std;
using ll = long long;

// wrong answer

bool isoperator(char c)
{
	return c == '+' or c == '-' or c == '*' or c == '/';
}

int priority(char c)
{
	if(c == '+' or c == '-') return 1;
	else if(c == '*' or c == '/') return 2;

	return -1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	faster();
	
	string s; cin >> s;
	vector<char> v;
	string ans = "";
	//operator
	REP(i, 0, s.size() - 1)
	{
		if(isalpha(s[i]))
			ans.push_back(s[i]);
		else if(s[i] == '(')
			v.push_back(s[i]);
		else if(s[i] == ')')
		{
			while(!v.empty() and v.back() != '(')
			{
				ans.push_back(v.back());
				v.pop_back();
			}
			v.pop_back();	
		}
		else if(isoperator(s[i]))
		{
			while(!v.empty() and priority(v.back()) >= priority(s[i]))
			{
				ans.push_back(v.back());
				v.pop_back();
			}
			v.push_back(s[i]);
		}
	}
	cout << ans;
}