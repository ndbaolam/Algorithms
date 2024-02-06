#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
const int MAX = 1e9+5;
ll mod = 1e9+7;

int n, a[20], final;
vector<vector<int>> res;

void init(string &s)
{
	for(int i=1;i<=n;i++)
		a[i]=1;
	for(int i=0;i<n;i++)
		s[i]='A'+i;
}

void sinh()
{
	int i=n;
	while(i>=1 && a[i]==n)
	{
		a[i]=1;
		--i;
	}
	if(i==0) final=1;
	else ++a[i];
}

int main()
{
	cin >> n;
	string s(n,'A');
	init(s);
	do{
		final=0;
		while(!final)
		{
			cout << s;
			for(int i=1;i<=n;i++)
				cout << a[i];
			cout << endl;
			sinh();
		}
	}while(next_permutation(all(s)));
}