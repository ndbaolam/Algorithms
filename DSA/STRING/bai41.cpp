#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s; cin >> s;
	int k; cin >> k;
	int n = (int)s.size();
	for(int i=n-1;i>=n-k;i--)
	{
		if(s[i]-'0')
		{
			cout <<"NO";
			return 0;
		}
	}
	cout << "YES";
}

