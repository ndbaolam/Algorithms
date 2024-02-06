#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sinh(int n)
{
	vector<int> v;
	v.push_back(1);
	while(!v.empty())
	{
		for(int j=0;j<v.size();j++)
			cout << v[j] << " ";
		cout << endl;

		if(*v.rbegin()!=n)
		{
			int x = *v.rbegin();
			++x;
			v.push_back(x);
		}
		else
		{
			v.pop_back();
			if(!v.empty())
				++(*v.rbegin());
		}
	}
}

int main()
{
	int n;
	cin >> n;
	sinh(n);
	return 0;
}