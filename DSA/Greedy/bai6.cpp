#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n], b[n];
	for(int &i : a) cin >> i;
	for(int &i : b) cin >> i;

	sort(a,a+n);
	sort(b,b+n);

	ll sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i]*b[i];

	cout << sum;
}