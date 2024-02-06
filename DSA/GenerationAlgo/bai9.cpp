#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[20], b[20], final;
vector<vector<int>> res;

void init()
{
	for(int i=1;i<=k;i++)
		b[i]=i;
}

void sinh()
{
	int i=k;
	while(i>=1 && b[i]==n-k+i)
		--i;
	if(i==0) final = 1;
	else
	{
		++b[i];
		for(int j=i+1;j<=k;j++)
			b[j]=b[j-1]+1;
	}
}

void khoitao()
{
	while(!final)
	{
		vector<int> tmp(b+1,b+k+1);
		res.push_back(tmp);
		sinh();
	}
}

int main()
{
	cin >> n >> k;
	for(int i=0;i<k;i++) cin >> a[i];
	init(); khoitao();
	
	for(int i=res.size()-1;i>=0;i--)
	{
		bool check = true;
		for(int j=0;j<k;j++)
		{
			if(res[i][j]!=a[j])
			{
				check=false;
				break;
			}
		}
		if(check)
		{
			cout << res.size()-i;
			return 0;
		}
	}
}