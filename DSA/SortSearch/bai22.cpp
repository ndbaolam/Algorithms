#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	set<char> s;
	for(int i=1;i<=n;i++)
	{
		string str;
		cin >> str;
		for(char c : str)
		{
			s.insert(c);
		}
	}
	for(char c : s)
		cout << c << " ";
	return 0;
}