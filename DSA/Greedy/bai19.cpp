#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	string s; cin >> s;
	stack<char> st;
	int cnt=0;
	for(char c : s)
	{
		if(c=='(') st.push(c);
		else if(c==')' && st.empty())
			++cnt;
		else if(c==')' && !st.empty())
			st.pop();
	}
	cout << cnt;
}