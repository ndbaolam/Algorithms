#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = (int)(1e9+1);

int prime[MAX];

void sieve()
{
	for(int i=0;i<MAX;i++)
		prime[i]=1;
	prime[0]=prime[1]=0;

	for(int i=2;i<1e5;i++)
	{
		if(prime[i])
		{
			for(int j=i*i;j<MAX;j+=i)
			{
				prime[j]=0;
			}
		}
	}
}

int main()
{
	int n; cin >> n;
	sieve();
	if(prime[n])
		cout << "YES\n";
	else cout << "NO\n";
}