#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Op{
	int l, r, d;
	//d: do dai cua day con
};

typedef Op Op;

bool cmp(Op a, Op b)
{
	return a.d < b.d;
}

vector<Op> m;

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a)
		cin >> i;

	ll sum=0;
	int l=0;
	bool check;

	for(int r=0;r<n;r++)
	{
		sum+=a[r];
		while(sum>=k)
		{
			check=true;
			m.push_back({l,r,r-l+1});
			sum-=a[l];
			++l;			
		}
	}
	if(check)
	{
		stable_sort(m.begin(),m.end(),cmp);
		for(int i = m[0].l; i <= m[0].r; i++)
			cout << a[i] << " ";
	}
	else cout << -1;

	return 0;
}