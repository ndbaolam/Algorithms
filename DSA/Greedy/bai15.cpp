#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int k, d; cin >> k >> d;
	if(k>9*d)
	{
		cout << -1; return 0;
	}

	string s(d,'0'); s[0]='1';
	--k;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(k<=9)
		{	
			if(i==0) ++k;
			s[i]=k+'0';
			break;
		}
		else
		{
			s[i]='9';
			k-=9;
		}
	}
	cout << s;
}