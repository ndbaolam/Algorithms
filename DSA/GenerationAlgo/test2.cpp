#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n=3;
	int a[n]={1,2,3};
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				cout << a[j] << ' ';
		cout << endl;
	}
	return 0;
}