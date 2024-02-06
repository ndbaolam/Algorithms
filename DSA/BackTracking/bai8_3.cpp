#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, k, cnt;
int a[25], x[25];
vector<vector<int>> res;

void back(int i, int pos)
{
	for(int j=pos;j<=n;j++)
	{
		x[i]+=a[j];
		if(i==n)
		{
			vector<int> tmp(x+1,x+i+1);
			res.push_back(tmp);
		}
		else
			back(i+1,j+1);
		x[i]-=a[j];
	}
}

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	back(1,1);
	bool check = false;
	for(auto v : res)
	{
		if(v.size()==k)
		{
			for(int i=1;i<v.size();i++)
			{
				if(v[i]==v[i-1]) check =true;
				else check = false;
			}
		}
	}
	if(check) cout << 1;
	else cout << 0;
}