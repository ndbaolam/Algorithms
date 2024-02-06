#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	ll res = 1ll*(v.begin()->first+v.begin()->second);
	for(int i=1;i<v.size();i++)
	{
		if(v[i].first < res)
			res+=v[i].second;
		else
			res+=(v[i].first-res)+v[i].second;
	}
	cout << res;
	return 0;
}