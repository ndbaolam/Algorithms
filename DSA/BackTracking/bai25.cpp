#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

string s, x="";
vector<vector<string>> res;
vector<string> S;

bool isPalin(string s)
{
	string tmp = s;
	reverse(all(s));
	return tmp == s;
}

void back(int i)
{
	if(i==s.size()) res.push_back(S);
	for(int j=i;j<s.size();j++)
	{
		string tmp = s.substr(i,j-i+1);
		if(isPalin(tmp))
		{
			S.push_back(tmp);			
			back(j+1);
			S.pop_back();			
		}		
	}
}

int main()
{
	cin >> s;
	back(0);
	for(auto v : res)
	{
		for(auto t : v)
			cout << t << ' ';
		cout << endl;
	}
}