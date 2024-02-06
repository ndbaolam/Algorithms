#include<bits/stdc++.h>
using namespace std;
using ll = long long;

string findMax(string a, string b)
{
	if(a.size()>b.size()) return a;
	else if(a.size()<b.size()) return b;
	else return max(a,b);
}

int main()
{
	string S;
	getline(cin,S);
	for(char &c : S)
		if(isalpha(c)) 
			c=' ';
	stringstream ss(S);
	vector<string> v;
	string tmp;
	while(ss >> tmp)
	{
		while(tmp.size()>1 && tmp[0]=='0')
			tmp.erase(0,1);
		v.push_back(tmp);
	}
	string res="0";
	for(string x : v)
		res= findMax(res,x);
	cout << res;
	return 0;
}