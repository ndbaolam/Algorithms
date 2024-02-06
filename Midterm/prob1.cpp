#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DREP(i,a,b) for(int i = (a); i >= (b); --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
// 17 + 8 * 2004 - 26

bool check(string s)
{
	if(!isdigit(s[0])) return false;
	if(!isdigit(s[s.size() - 1])) return false;
	REP(i, 1, s.size() - 1)
	{
		if(!isdigit(s[i]) && !isdigit(s[i-1])) return false;
	}
	return true;
}

void process_op(stack<ll>& st, char op)
{
	ll r = st.top(); st.pop();
	ll l = st.top(); st.pop();
	switch(op)
	{
		case '+': st.push((l + r) % mod); break;
		case '*': st.push((l * r) % mod); break;
	}
}

int evaluate(string& s)
{
	stack<ll> st;
	stack<char> op;
	for(int i = 0; i < (int)s.size(); i++)
	{
		if(s[i] == '+' || s[i] == '*')
		{
			char cur_op = s[i];
			while(!op.empty() && op.top() == '*')
			{
				process_op(st, op.top());
				op.pop();
			}
			op.push(cur_op);
		}
		else
		{
			ll number = 0;
			while(i < (int)s.size() && isalnum(s[i]))
				number = number * 10 + s[i++] - '0';
			--i;
			st.push(number);
		}
	}
	while(!op.empty())
	{
		process_op(st, op.top());
		op.pop();
	}
	return st.top();
}
int main()
{
	string s; cin >> s;
	if(!check(s)) cout << "NOT_CORRECT";
	else cout << evaluate(s) << endl;
}

