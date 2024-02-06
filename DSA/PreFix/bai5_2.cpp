#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 1000

int F[MAX];

int main()
{
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int &i : a)
		cin >> i;
	while(q--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		for(int i=l;i<=r;i++)
			a[i]+=k;
	}
	for(int i : a)
		cout << i << " ";
}