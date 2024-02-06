#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	int cnt=0, pos=0;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[pos]+4)
		{
			pos=i;
			++cnt;
		}
	}
	cout << ++cnt;
}