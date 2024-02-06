#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, s; cin >> n >> s;
	int a[n];
	for(int i=0; i<n;i++) cin >> a[i];

	multiset<int> ms;
	int l=0, cnt=0;
	ll ans=0;
	int k;

	for(int r=0;r<n;r++)
	{
		ms.insert(a[r]);

		while(*ms.rbegin()-*ms.begin()>s)
		{
			ms.erase(ms.find(a[l]));
			++l;
		}
		ans+=r-l+1;
	}

	cout << ans << endl;
}
