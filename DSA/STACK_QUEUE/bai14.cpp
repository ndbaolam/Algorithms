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
	stack<int> st;
	DREP(i, s.size() - 1, 0)	
	{
		if(isdigit(s[i]))
			st.push(s[i] - '0');
		else
		{
			int t1 = st.top(); st.pop();
			int t2 = st.top(); st.pop();
			if(s[i] == '+') st.push(t1 + t2);
			else if(s[i] == '-') st.push(t1 - t2);
			else if(s[i] == '*') st.push(t1 * t2);
			else st.push(t1 / t2);
		}
	}
	cout << st.top();
}