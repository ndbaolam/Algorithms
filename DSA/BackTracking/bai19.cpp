#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n;
int x[20], a[20];
vector<vector<int>> res;

void back(int i, int pos,  int sum)
{
	for(int j=pos;j<=n;j++)
	{
		sum+=a[j];
		x[i]=a[j];
		if(sum&1)
		{
			vector<int> tmp(x+1,x+i+1);
			res.push_back(tmp);
		}
		back(i+1,j+1,sum);
		sum-=a[j];
	}
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	back(1,1,0);
	if(!res.empty())
	{
		sort(all(res));
		for(auto x : res)
		{
			for(auto i : x)
				cout << i << ' ';
			cout << endl;
		}
	}
	else cout << "NOT FOUND";
}