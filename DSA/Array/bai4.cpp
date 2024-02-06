#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(int a[], int n)
{
	int d25=0,d50=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==25) d25++;
		else if(a[i]==0){
			if(d25>=1){
				d50++; d25--;
			}
			else return 0;
		}
		else
		{
			if(d25>=1&&d50>=1)
			{
				d25--;
				d50--;
			}
			else if(d25>=3) d25-=3;
			else return 0;
		}
	}
	return 1;
}
int main()
{
	int n; cin >> n;
	int a[n];
	for(int &x:a)
		cin >>x;
	if(check(a,n))
		cout << "YES";
	else cout << "NO";
}