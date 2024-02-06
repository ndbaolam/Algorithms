#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
const int MAX = 1e9+5;
ll mod = 1e9+7;

int n, a[25], final;
vector<ll> res;
ll T;

void sinh()
{
	for(int i=0;i<(1<<n);i++)
	{
		ll sum=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				sum+=a[j];
			}
		}
		res.push_back(abs(T-2*sum));
	}
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		T+=a[i];
	}
	sinh();
	cout << *min_element(all(res));
}