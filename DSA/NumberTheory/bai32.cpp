#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k; cin >> n >> k;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{	
			while(n%i==0)	
			{
				n/=i;
				--k;
				if(k==0)
				{
					cout << i;
					return 0;
				}
			}
		}
	}
	if(n!=1 && k==1)
		cout << n;
	else cout << -1;
}