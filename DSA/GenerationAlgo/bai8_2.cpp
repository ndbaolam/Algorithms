#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[15], b[15], final;
vector<vector<int>> res;

void sinh()
{
	for(int i=0;i<n;i++)
		b[i]=i+1;
	do{
		vector<int> tmp(b,b+n);
		res.push_back(tmp);
	}while(next_permutation(b,b+n));
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sinh();
	for(int i=0;i<res.size();i++)
	{
		bool check = true;
		for(int j=0;j<n;j++)
		{
			if(res[i][j]!=a[j])
			{
				check=false;
				break;
			}
		}
		if(check)
		{
			cout << i+1;
			return 0;
		}
	}
	return 0;
}