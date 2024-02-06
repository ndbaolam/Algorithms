#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
int a[1005];
int final;

void sinh()
{
	int i=k;
	while(i>=1 && a[i]==n-k+i)
		--i;
	if(i==0)
		final = 1;
	else
	{
		++a[i];
		for(int j=i+1;j<=k;j++)
			a[j]=a[j-1]+1;
	}
}

int main()
{
	cin >> n >> k;
	for(int i=1;i<=k;i++)
		cin >> a[i];

	sinh();
	if(!final)
		for(int i=1;i<=k;i++)
			cout << a[i] << " ";
	else
		for(int i=1;i<=k;i++)
			cout << i << " ";
	return 0;
}