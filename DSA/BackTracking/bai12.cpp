#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair <int,int>;

const int INF = 1e9;
const int MAX = 1e9+5;
const ll mod = 1e9+7;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int a[n];
	for(int &i : a)
		cin >> i;

	
	for(int i=0;i<(1<<n);i++)
	{
		ll sum=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) sum+=a[j];
			else sum-=a[j];
			
		}
		if(sum==0) 
			{
				cout << 1;
				return 0;
			}
	}
	cout << 0;
}