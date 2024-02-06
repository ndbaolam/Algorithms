#include <bits/stdc++.h>
using namespace std;

bool ngto(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)return false;
	}
	return n>1;
}
int main()
{
	int x;
	map<int,int> mp;
	vector<int> v;
	while(cin >> x)
	{
		if(ngto(x))
		{
			mp[x]++;
			if(mp[x]==1)	v.push_back(x);
		}
	}

	for(int i : v)
		cout << i << " " << mp[i] << endl;

	
	return 0;
}