#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 105

int dx[3]={-1,-1,-1};
int dy[3]={-1,0,1};
int a[MAX][MAX];
ll d[MAX][MAX];

int main()
{
	int n; cin >> n;
	map<int,int> mp;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
			if(mp[a[i][j]]==i-1)
				mp[a[i][j]]++;
		}
	}
	bool check = false;
	for(auto i : mp)
	{
		if(i.second==n)
		{
			check= true;
			cout << i.first << " ";
		}
	}
	if(!check)
		cout << "NOT FOUND";
}