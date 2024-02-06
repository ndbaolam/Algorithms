#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[15], final;

void sinh()
{
	int i=n-1;
	while(i>=0 && a[i]==1)
	{
		a[i]=0;
		--i;
	}
	if(i==-1)
		final=-1;
	else
		a[i]=1;
}
int main()
{
	cin >> n;
	while(!final)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
				cout << "B";
			else cout << "A";
		}
		cout << endl;
		sinh();
	}
	return 0;
}