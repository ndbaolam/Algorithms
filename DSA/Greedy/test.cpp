#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int cnt=0, i=0;
	int money[10] = {1000,500,200,100,50,20,10,5,2,1};
	while(money[i]>n) ++i;
	while(n)	
	{
		if(money[i]<=n)
		{
			n-=money[i];
			++cnt;	
		}	
		else ++i;
	}
	cout << cnt;
}