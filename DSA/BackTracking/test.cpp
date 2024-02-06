#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, k;
int a[50], x[50];
vector<vector<int>> res;
int sum;

void back(int i, int pos)
{
	if(i==n+1) return;
	for(int j=pos;j<=n;j++)
	{
		if(sum+a[j] <= k)
		{
			sum+=a[j];
			x[i]=a[j];
			if(sum==k)
			{
				vector<int> tmp(x+1,x+i+1);
				res.push_back(tmp);
			}
			else back(i+1,j+1);
			sum-=a[j];
		}
	}
}

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	back(1,1);
	for(auto x :res)
	{
		for(int y : x)
			cout << y << ' ';
		cout << endl;
	}
}