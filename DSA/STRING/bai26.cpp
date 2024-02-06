#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;
	set<pair<int,char>> v;
	int cnt=1, res=0;
	s+="@";
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]==s[i+1])
		{
			++cnt;
		}
		else
		{
			if(cnt>res) res=cnt;
			v.insert({cnt,s[i]});
			cnt=1;
		}
	}
	for(int i=0;i<res;i++)
	{
		cout << (*v.rbegin()).second;
	}
}