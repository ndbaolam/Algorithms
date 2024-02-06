#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char,int> a, pair<char,int> b)
{
	if(a.second!=b.second)
		return a.second > b.second;
	else return a.first < b.first;
}

int main()
{
	char S;
	map<char,int> mp;
	while(cin >> S)
		mp[S]++;
	vector<pair<char,int>> v;
	for(auto i : mp)
		v.push_back(i);
	sort(v.begin(),v.end(),cmp);
	cout << v.begin()->first << " " << v.begin()->second <<endl;
	cout << v.rbegin()->first << " " << v.rbegin()->second << endl;
	cout << mp.size();
}