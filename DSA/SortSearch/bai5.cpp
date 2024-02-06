#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<ll,int> a, pair<ll,int> b)
{
	if(a.second!=b.second)
		return a.second>b.second;
	else return a.first<b.first;
}

int main()
{
	int n; cin >> n;
	ll a[n];
	map<ll,int> mp;
	for(int i=0; i<n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<pair<ll,int>> v;
	for(auto i : mp)
	{
		v.push_back({i.first,i.second});
	}

	sort(v.begin(),v.end(),cmp);
	cout << v.begin()->first << " " << v.begin()->second;

}