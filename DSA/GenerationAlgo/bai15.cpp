#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	string s; cin >> s;
	set<char> se;
	vector<char> v;
	for(char i : s)
	{
		if(!se.count(i))
			v.push_back(i);
		se.insert(i);
	}

	sort(v.begin(), v.end());
	do{
		for(int i=0;i<v.size();i++)
			cout << v[i];
		cout << endl;
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}