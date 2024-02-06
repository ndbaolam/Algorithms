#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, k;
int a[50], x[50];
vector<vector<int>> res;

void back(int i, int pos, int sum)
{
	for(int j=pos;j<=n;j++)
	{
		x[i]=a[j];
		sum+=x[i];
		if(sum==k)
		{
			vector<int> tmp(x+1,x+1+i);
			res.push_back(tmp);
		}
		else if(sum<k) back(i+1,j,sum);
		sum-=x[i];
	}
}

// void Try(int i, int sum, int pos)
// {
// 	for(int j=pos;j<=n;j++)
// 	{
// 		X[i] = a[j];
// 		sum += X[i];
// 		if(sum==S)
// 		{
// 			check = true;
// 			vector<int> tmp(X+1,X+i+1);
// 			res.push_back(tmp);
// 		}
// 		else if(sum<S) Try(i+1,sum,j);
// 		sum-=X[i];
// 	}
// }

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n;i++) 
		cin >> a[i];
	sort(a+1,a+n+1);
	
	back(1,1,0);
	for(auto i : res)
	{
		for(int j : i)
			cout << j << ' ';
		cout << endl;
	}
}