#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sinh(string a, int n)
{
	int i;
	for(i=n-1;i>=0,a[i]=='1';i--)
		a[i]='0';
	if(i!=-1)
	{
		a[i]='1';
		cout << a;
	}
	else
		for(int i=0;i<n;i++) cout << 0;
}

int main()
{
	string a; cin >> a;
	sinh(a, (int)a.length());
	return 0;
}