#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[15], final;

void init()
{
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
}
void sinh()
{
	int i=n-1;
	while(i>=1 && a[i]>a[i+1])
		--i;
	if(i==0) final=1;
	else
	{
		reverse(a+i+1,a+n+1);
		auto it = lower_bound(a+i+1,a+n+1,a[i]);
		swap(a[i],*it);
	}
}
int main()
{
	cin >> n;
	vector<vector<int>> v;
	init();
	while(!final)
	{
		vector<int> tmp;
		for(int i=1;i<=n;i++)
			tmp.push_back(a[i]);
		v.push_back(tmp);
		sinh();
	}
	for(auto it = v.rbegin(); it!=v.rend();it++)
	{
		for(auto it1 : *it)
			cout << it1;
		cout << endl;
	}
	return 0;
}