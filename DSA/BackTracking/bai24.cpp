#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

string s;
set<string> res;
string tmp;

void back(int pos)
{
	for(char x : {tolower(s[pos]),toupper(s[pos])})
	{
		tmp+=x;
		if(tmp.size()==s.size())
			res.insert(tmp);
		else back(pos+1);
		tmp.pop_back();
	}
}

int main()
{
	cin >> s;
	back(0);
	for(string x: res)
		cout << x << endl;
}