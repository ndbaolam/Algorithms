#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

bool isPalin(map<char,int> mp)
{
	int odd=0;
	for(auto [x,y] : mp)
		if(y&1) ++odd;
	return odd <= 1;
}

int main()
{
	string s; cin >> s;
	map<char,int> mp;	
	int cnt=0;
	for(char c : s) mp[c]++;

	while(!isPalin(mp))
	{
		for(auto [x,y] : mp)	
		{
			if(y&1) 
			{
				mp.erase(x);
				break;
			}
		}
		++cnt;
	}
	if(cnt&1) cout << 2;
	else cout << 1;
}