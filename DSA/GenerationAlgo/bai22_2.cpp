#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
const int MAX = 1e9+5;
ll mod = 1e9+7;

int final, n;
vector<string> res;

void sinh(string &s)
{
	int i=s.length()-1;
	while(i>=0 && s[i]=='8')
	{
		s[i]='6';
		--i;
	}
	if(i==-1) final=1;
	else if(s[i]=='0') s[i]='6';
	else s[i]='8';
}

int main()
{
	cin >> n;
	string s(16,'0');
	s+='6';
	while(!final)
	{
		string tmp = to_string(stoll(s));
		res.push_back(tmp);
		sinh(s);
	}
	
	for(int i=0;i<n;i++)
	{
		string tmp = res[i];
		reverse(all(res[i]));
		cout << tmp << res[i] << " ";
	}
}