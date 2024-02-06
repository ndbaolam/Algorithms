#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int n)
{
	int sum=0;
	bool is6 = false;
	while(n)
	{
		int x = n%10;
		sum+=x;
		if(x==6)
			is6=true;
		n/=10;
	}
	int lst = sum%10;
	return lst==8 && is6;
}

bool isPalin(int n)
{
	int tmp = n;
	int x=0;
	while(tmp)
	{
		x=x*10+tmp%10;
		tmp/=10;
	}
	return x==n;
}
int main()
{
  	int l, r; cin >> l >> r;
  	for(int i=l;i<=r;i++)
  	{
  		if(check(i) && isPalin(i))
  			cout << i << " ";
  	}
}