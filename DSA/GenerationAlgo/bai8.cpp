#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[15], b[15], final;
// b[]: luu tat ca hoan vi
// a[]: luu hoan vi dc cho

void init()
{
	for(int i=1;i<=n;i++)
		b[i]=i;
}

void sinh()
{
	int i=n-1;
	while(i>=1 && b[i] < b[i+1])
		--i;
	if(i==0)
		final=1;
	else
	{
		reverse(b+i+1,b+n+1);
		auto it = lower_bound(b+i+1,b+n+1,b[i]);
		swap(b[i],*it);
	}
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++) 
		cin >> a[i];

	init();	
	vector<vector<int>> res;
	while(!final)
	{
		vector<int> tmp(b+1,b+n+1);
		res.push_back(tmp);
		sinh();
	}

	for(int i=0;i<res.size();i++)
	{
		bool check = true;
		for(int j=0;j<n;j++)
		{
			if(res[i][j]!=a[j])
			{
				check =false;
				break;
			}
		}
		if(check)
		{
			cout << i+1;
			return 0;
		}
	}	
}