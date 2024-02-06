#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string n;
	cin >> n;
	map<int,int> mp;
	for(char c : n)
	{
		int x = c-'0';
		if(x==2||x==3||x==5||x==7)
			mp[x]++;
	}
	for(auto i : mp)
		cout << i.first << " " << i.second << endl;
	cout << endl;
	set<int> s;
	for(char c : n)
	{
		int x = c-'0';
		if(x==2||x==3||x==5||x==7)
		{
			if(!s.count(x))
				cout << x << " " << mp[c-'0'] << endl;	
			s.insert(x);
		}
	}
}