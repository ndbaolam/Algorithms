#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; cin >> s;

	if(s.size()==1)
	{
		cout << s;
		return 0;
	}

	set<pair<int,string>> v;
	int cnt=1;
	string tmp="";

	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			++cnt;
			tmp+=s[i];
		}
		else
		{
			tmp+=s[i];
			++cnt;

			v.insert({cnt,tmp});
			cnt=1;
			tmp="";
		}
		if(i==s.size()-2)
		{
			tmp+=s[i+1];
			++cnt;
			v.insert({cnt,tmp});
		}
	}

	cout << (*v.rbegin()).second;
}