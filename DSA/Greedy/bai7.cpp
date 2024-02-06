#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}

int main()
{
	int n; cin >> n;
	vector<pair<int,int>> v;
	while(n--)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({start,end});
	}
	sort(all(v),cmp);
	int cnt=1;
	int k = v[0].second;
	for(int i=0;i<v.size();i++)
	{
		if(k<v[i].first)
		{
			++cnt;
			k=v[i].second;
		}
	}
	cout << cnt;
}