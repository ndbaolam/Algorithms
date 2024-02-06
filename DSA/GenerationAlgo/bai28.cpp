#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
using ll = long long;
const int MAX = 1e9+5;
ll mod = 1e9+7;
int a[4];
vector<ll> res;

void sinh()
{
	for(int i=0;i<(1<<3);i++)
	{
		ll sum=a[0];
		for(int j=1;j<=3;j++)
		{
			if(i&(1<<j)) sum+=a[j];
			else sum-=a[j];
		}
		res.push_back(sum);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int &i : a) cin >> i;
	sinh();
	cout << *max_element(all(res));
}