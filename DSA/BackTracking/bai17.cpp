#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
	
int n;
string tmp = "()[]{}";
string s;
vector<string> res;

bool check(string s)
{
	stack<char> st;
	for(char x : s)
	{
		if(x=='(' || x=='[' || x=='{')
			st.push(x);
		else
		{
			if(st.empty()) return false;
			char y = st.top();
			st.pop();
			if((x==')'&&y!='(') || (x=='}'&&y!='{') || (x==']'&&y!='['))
				return false;
		}
	}
	return st.empty();
}

void back()
{
	for(int j=0;j<tmp.size();j++)
	{
		s+=tmp[j];
		if(s.size()==n)
		{
			if(check(s))
				res.push_back(s);
		}
		else back();
		s.pop_back();
	}
}

int main()
{
	cin >> n;
	if(!(n&1))
	{
		back();
		sort(all(res));
		for(auto x : res)
			cout << x << ' ';
	}
	else cout << "NOT FOUND";
}