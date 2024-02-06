#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N; cin >> N;
	string s, tmp;
	map<string,set<string>> mp;
	while(N--)
	{
		getline(cin, s);
		for(auto &i : s)
			if(i=='-')
				i = ' ';
		stringstream S(s);
		while(S >> tmp)
			
	}
}