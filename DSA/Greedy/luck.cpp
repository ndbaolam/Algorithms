#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.second != b.second)
		return a.second > b.second;
	else return a.first > b.first;
}

int main()
{
	int n, k; cin >> n >> k;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}
	sort(all(v),cmp);
	int ans=0;
	for(auto [x,y] : v)
	{
		if(y==0) ans+=x;
		else
		{
			if(--k>=0) ans+=x;
			else ans-=x;
		}
	}
	cout << ans;
}