#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, m, k; cin >> n >> m >> k;
	int a[n], b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];

	int cnt=0;
	sort(a,a+n);
	sort(b,b+m);
	int i=0, j=0;
	while(i<n && j<m)
	{
		if(abs(a[i]-b[j])<=k)
		{
			++cnt;
			++i;
			++j;
		}
		else if(a[i]>b[j])
			++j;
		else ++i;
	}
	cout << cnt;
}