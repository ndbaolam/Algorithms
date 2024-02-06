#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.first!=b.first)
		return a.first < b.first;
	else return a.second < b.second;
}

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		v.push_back({a[i],i});
	}
	sort(v.begin(),v.end(), cmp);
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i].first==v[i+1].first)
		{
			if( v[i+1].second - v[i].second < k)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}