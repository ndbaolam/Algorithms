#include <bits/stdc++.h>
using namespace std;

bool check(int n)
{
	int num1=0;
	int num2=0;
	while(n)
	{
		num1=n%10;
		n/=10;
		num2=n%10;
		if(num2>num1) return false;
	}
	return true;
}
bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}
int main()
{
	int n;
	map<int,int> mp;
	while(cin >> n)
	{
		if(check(n))
			mp[n]++;
	}

	vector<pair<int,int>> v;
	for(auto i : mp)
		v.push_back(i);
	sort(v.begin(),v.end(),cmp);
	for(auto i : v)
		cout << i.first << " " << i.second << endl;
}