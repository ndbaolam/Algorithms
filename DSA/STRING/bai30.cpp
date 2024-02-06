#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(string a, string b)
{
	int n = (int)a.size();
	int m = (int)b.size();
	int mini = min(n,m);
	for(int i=0;i<mini;i++)
	{
		if(a[i]!=b[i])
			return a[i]>b[i];
	}
	return a<b;
}

int main()
{
	string s;
	cin >> s;
	s+="a";
	string tmp="";
	vector<string> v;
	for(char x : s)
	{
		if(isdigit(x))
		{
			tmp+=x;
		}
		else
		{
			v.push_back(tmp);
			tmp="";
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i : v)
		cout << i;
}