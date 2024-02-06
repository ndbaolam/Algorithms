#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[20], b[20], final;

void init()
{
	for(int i=1;i<=n;i++)
		a[i]=0;
	for(int i=n-k+1;i<=n;i++)
		b[i]=1;
}

void next()
{
	int i=n;
	while(i>=1 && a[i]==1)
	{
		a[i]=0;
		--i;
	}
	if(i==0) final = 1;
	else
		a[i]=1;
}

bool check()
{
	int res=0;
	for(int i=1;i<=n;i++)
		res+=a[i];
	return res==k;
}

int main()
{
	cin >> n >> k;
	init();
	while(!final)
	{
		if(check())
		{
			for(int i=1;i<=n;i++)
				cout << a[i];
			cout << ' ';
		}
		next();
	}
	cout << endl;

	for(int i=1;i<=n-k+1;i++)
	{
		for(int j=i;j<=n+i-1;j++)
			cout << b[j];
		cout << " ";
	}
}