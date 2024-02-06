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
	stack<string> st;
	REP(i, 0, s.size() - 1)	
	{
		if(isalpha(s[i]))
			st.push(string(1, s[i]));
		else
		{
			string t1 = st.top(); st.pop();
			string t2 = st.top(); st.pop();
			string tmp = "(" + t2 + s[i] + t1 + ")";
			st.push(tmp);
		}
	}
	cout << st.top();
}