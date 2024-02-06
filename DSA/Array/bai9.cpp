#include <bits/stdc++.h>
using namespace std;
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
	for(auto i : mp)
		cout << i.first <<" " << i.second << endl;
	cout << endl;
	set<int> s;
	for(int i =0;i<n;i++)
	{
		if(s.find(a[i])==s.end())
		{
			cout << a[i] << " " << mp[a[i]] << endl;
			s.insert(a[i]);
		}
	}
	return 0;
}