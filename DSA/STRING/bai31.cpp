#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(string s)
{
	int sum=0;
	for(char i : s)
	{
		sum+=i-'0';
	}
	if(sum%3==0 && (s[s.size()-1]-'0')%2==0)
		return true;
	else return false;
}
int main()
{
	string s;
	cin >> s;
	if(check(s)) cout << "YES";
	else cout << "NO";
}