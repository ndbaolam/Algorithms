#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	map<int,int> mp;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}
	ll sum=0;
	for(pair<int,int> i : mp)
	{
		if(i.second>1)
		{
			int x = i.second;
			sum+=(x-1)*x/2;
		}
	}
	cout << sum;
}