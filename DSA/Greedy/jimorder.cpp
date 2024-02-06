#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

bool cmp(pair<int,ll> a, pair<int,ll> b)
{
	if(a.second != b.second)
		return a.second < b.second;
	else return a.first < b.first;
}

int main()
{
	int n; cin >> n;
	vector<pair<int,ll>> v;
	for(int i=1;i<=n;i++)
	{
		ll a, b; cin >> a >> b;
		v.push_back({i,a+b});
	}
	sort(all(v),cmp);
	for(auto [x,y] : v)
		cout << x << ' ';
}