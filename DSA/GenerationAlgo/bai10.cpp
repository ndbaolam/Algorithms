#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[10], final;

void init()
{
	for(int i=1;i<=k;i++)
		a[i]=1;
}

void sinh()
{
	int i=k;
	while(i>=1 && a[i]==n)
	{
		a[i]=1;
		--i;
	}
	if(i==0) final = 1;
	else
	{
		++a[i];
	}
}
int main()
{
	cin >> n >> k;
	init();
	while(!final)
	{
		for(int i=1;i<=k;i++)
			cout << a[i];
		cout << endl;
		sinh();
	}
	return 0;
}