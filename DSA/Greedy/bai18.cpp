#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	map<int,int> mp;
	for(int &i : a)
	{
		cin >> i;
		mp[i]++;
	}
	ll res=0;
	if(mp.count(4)) res+=mp[4];

	if(mp.count(3))
	{
		res+=mp[3];
		if(mp.count(1))
		{
			mp[1] -= mp[3];
			if(mp[1]==0) mp.erase(1);
		}
	}

	if(mp.count(2))
	{
		res+=mp[2]/2;
		mp[2]%=2;
		if(mp[2]==0) mp.erase(2);
	}

	if(!mp.count(1) && !mp.count(2));
	else if(mp.count(1) && !mp.count(2))
	{
		if(mp[1]%4==0)
			res+=mp[1]/4;
		else
		{
			res+=mp[1]/4;
			res++;
		}
	}
	else if(!mp.count(1) && mp.count(2))
		++res;
	else
	{
		++res;
		mp[1]-=2;
		if(mp[1]>0)
		{
			if(mp[1]%4==0)
			res+=mp[1]/4;
		else
		{
			res+=mp[1]/4;
			res++;
		}
		}
	}
	cout <<res;
}