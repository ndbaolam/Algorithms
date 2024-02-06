#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	int a[n]; 
	for(int &i : a) cin >> i;
	sort(a,a+n);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		k-=a[i];
		if(k>0) ++cnt;
		else break;
	}
	cout << cnt;
}