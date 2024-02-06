#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, a[15], b[15];
	cin >> n;
	for(int i=0;i<n;i++) 
		cin >> a[i];
	int cnt=0;
	for(int i=0;i<n;i++)
		b[i]=i+1;
	do{
		++cnt;
		bool check = true;
		for(int j=0;j<n;j++)
		{
			if(b[j]!=a[j])
			{
				check=false;
				break;
			}
		}
		if(check)
		{
			cout << cnt;
			return 0;
		}
	}while(next_permutation(b,b+n));
	return 0;
}