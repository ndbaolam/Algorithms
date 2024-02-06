#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 200


int main()
{
	int n;
	cin >> n;
	ll a[n][n];

	int h1=0, h2=n-1, c1=0, c2=n-1, cnt=0;

	ll fibo[100];
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<100;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];

	while(h1<=h2 && c1<=c2)
	{
		// xay dung dong tren cung
		for(int i=c1;i<=c2;i++)
		{
			a[h1][i]=fibo[cnt];
			++cnt;
		}
		++h1;

		for(int i=h1;i<=h2;i++)
		{
			a[i][c2]=fibo[cnt];
			++cnt;
		}
		--c2;

		if(c1<=c2)
		{
			for(int i=c2;i>=c1;i--)
			{
				a[h2][i]=fibo[cnt];
				++cnt;
			}
			--h2;
		}

		if(h1<=h2)
		{
			for(int i=h2;i>=h1;i--)
			{
				a[i][c1]=fibo[cnt];
				++cnt;
			}
			++c1;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}