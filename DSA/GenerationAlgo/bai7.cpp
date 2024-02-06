#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	vector<string> v;
	for(int i=1;i<=n;i++)
	{
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	do{
		for(auto i : v)
			cout << i << " ";
		cout << endl;
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}