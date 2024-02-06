#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

void solve(int n)
{
	if(n%7==0)
	{
		int x = n/7;
		for(int i=1;i<=x;i++)
			cout <<7;
	}
	else
	{
		int a = n/7;
		if(n%7==4)
		{
			cout << 4;
			for(int i=1;i<=a;i++)
				cout << 7;
		}
		else
		{
			if(n%4 == 0)
			{
				int b = n/4;
				for(int i=1;i<=b;i++)
					cout << 4;
			}
			else cout << -1;
		}
	}
}

int main()
{
	int n; cin >> n;
	solve(n);
}