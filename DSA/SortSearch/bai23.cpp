#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6+5;

int a[maxn], b[maxn];

bool cmp1(pair<int,int> a, pair<int,int> b)
{
	if(a.second != b.second)
		return a.second > b.second;
	else return a.first < b.first;
}

bool cmp2(pair<int,int> a, pair<int,int> b)
{
	return a.second > b.second;
}

int main()
{
	int n; cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	vector<pair<int,int>> v, u;
	set<int> s;

	for(int i=0;i<n;i++)
	{
		if(!s.count(a[i]))
		{
			v.push_back({a[i],b[a[i]]});
			u.push_back({a[i],b[a[i]]});
		}
		s.insert(a[i]);
	}

	sort(v.begin(),v.end(),cmp1);
	for(auto i : v)
	{
		for(int j=0;j<i.second;j++)
			cout << i.first << " ";
	}
	cout << endl;
	stable_sort(u.begin(),u.end(),cmp2);
	for(auto i : u)
	{
		for(int j=0;j<i.second;j++)
			cout << i.first << " ";
	}
	return 0;
}