#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

string s[10];
string num;
char x[100];
int n;

void prepare()
{
	s[2]="abc";
	s[3]="def";
	s[4]="ghi";
	s[5]="jkl";
	s[6]="mno";
	s[7]="pqrs";
	s[8]="tuv";
	s[9]="wxyz";
}

void back(int i)
{
	int phone = num[i]-'0';
	for(char j : s[phone])
	{
		x[i]=j;
		if(i==n-1)
		{
			for(int u=0;u<n;u++) cout << x[u];	
			cout << ' ';
		}
		else back(i+1);
	}
}

int main()
{
	prepare();
	cin >> num;
	sort(all(num));
	n=num.length();
	back(0);
}