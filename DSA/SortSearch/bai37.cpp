#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	vector<pair<int,int>> v;
	int cnt=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a,1});
		v.push_back({b,-1});
	}
	sort(v.begin(),v.end());
	for(auto i : v)
	{
		cnt+=i.second;
		ans=max(ans,cnt);
	}
	cout << ans;
}