#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(),x.end()
const int MAX = 1e9+5;
ll mod = 1e9+7;

int k, final;
char c;
void sinh(string &s)
{
	int i=s.length()-1;
	while(i>=0 && s[i]==c)
	{
		s[i]='A';
		--i;
	}
	if(i==-1) final=1;
	else
		++s[i];
}

int main()
{	
	cin >> c >> k;
	string s(k,'A');
	while(!final)
	{
		cout << s << endl;
		sinh(s);
	}
}