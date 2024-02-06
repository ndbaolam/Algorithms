#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s; cin >> s;
	int tmp = 1, sum=0;

	for(int i=s.size()-1;i>=0;i--)
	{
		sum+=(s[i]-'0')*tmp;
		tmp*=2;
		tmp%=10;
		sum%10;
	}

	if(sum%5==0)
		cout << "YES";
	else cout << "NO";
}

//1011 = 1 + 4 + 8 = 13