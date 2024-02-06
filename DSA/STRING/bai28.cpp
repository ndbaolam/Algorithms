#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	
	ll ans=0;
	ll sum=0;
	
	for(char x : s)
	{
		if(isdigit(x))
		{
			sum = sum*10+x-'0';
		}
		else
		{
			ans=max(ans,sum);
			sum=0;
		}
	}
	ans=max(ans,sum);
	cout << ans;
}