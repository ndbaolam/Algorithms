#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	string st="";
	int a[9]={1,2,3,5,6,9,13,17,10};
	for(int i=0;i<9;i++)
	{
		if(n==a[i]) 
		{
			cout << -1; 
			return 0;
		}
	}

	while(n!=0)
	{
		if(n%7==0) 
		{
			st.push_back('7');
			n-=7;
		}
		else
		{ 
			st.push_back('4');
			n-=4;
		}
	}
	if(st.empty()) cout << -1;
	else
	{
		for(int i=0;i<st.size();i++)
			cout << st[i];
	}
}