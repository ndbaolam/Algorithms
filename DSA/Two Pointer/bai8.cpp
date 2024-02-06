#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, s; cin >> n >> s;
	int a[n];
	for(int &i : a) cin >> i;

	map<int,int> mp;
	int l=0, cnt=0;
	ll ans=0;
	for(int r=0;r<n;r++)
	{
		mp[a[r]]++;
		if(mp[a[r]]==1) cnt++;
		while(cnt>s)
		{
			if(mp[a[l]]==1) --cnt;
			mp[a[l]]--;
			++l;			
		}
		ans+=r-l+1;
	}
	cout << ans << endl;
}
