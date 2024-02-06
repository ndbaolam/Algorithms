#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;

	map<int,int> mp;
	ll ans=0,cnt=0;
	int l=0;
	for(int r=0;r<n;r++)
	{	
		mp[a[r]]++;
		while(mp[a[r]]>1)
		{
			mp[a[l]]--;
			++l;
		}
		cnt=r-l+1;
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}


