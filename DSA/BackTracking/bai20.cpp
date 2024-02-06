#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int n, k;
string s;
string x = "";

void back(int i, int pos)
{
	for(int j=pos;j<n;j++)
	{
		x[i]=s[j];
		if(i==k-1) 
		{
			for(int u=0;u<k;u++)
				cout << x[u];
			cout << endl;
		}
		else back(i+1,j);
	}
}

int main()
{
	cin >> n >> k;
	cin >> s;
	sort(all(s));
	back(0,0);
}