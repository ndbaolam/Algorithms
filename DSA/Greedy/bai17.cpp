#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a,a+n);
	if(n==1) cout << a[0];
	else if(n==2) cout << a[0]*a[1];
	else
	{
		ll ans[5];
		ans[0] = 1ll* a[0] * a[1];
		ans[1] = 1ll* a[n-1] * a[n-2];
		ans[2] = 1ll* a[n-1] * a[n-2]* a[n-3];
		ans[3] = 1ll* a[0] * a[1]* a[n-1];
		ans[4] = 1ll* a[0] * a[n-2]* a[n-1];
		cout << *max_element(ans,ans+5);
	}
}	