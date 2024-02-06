#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a) cin >> i;
	int l=0;
	ll cnt=0;
	map<int,int> mp;

	for(int r=0;r<n;r++)
	{
		mp[a[r]]++;
		while(mp.size()>k)
		{
			mp[a[l]]--;
			if(mp[a[l]]==0)
				mp.erase(a[l]);
			++l;
		}
		cnt += r-l+1;
	}
	cout << cnt;
	return 0;
}