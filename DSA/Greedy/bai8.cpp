#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

struct job{
	int id, dl, profit;
};

typedef job Job;

bool cmp(Job a, Job b)
{
	return a.profit > b.profit;
}

int main()
{
	int n; cin >> n;
	Job a[n+1];
	for(int i=1;i<=n;i++)
		cin >> a[i].id >> a[i].dl >> a[i].profit;
	bool used[100005]={false};
	sort(a+1,a+n+1,cmp);
	ll res=0;
	

	for(int i=1;i<=n;i++)
	{
		for(int j=a[i].dl;j>=1;j--)
		{
			if(!used[j])
			{
				res+=a[i].profit;
				used[j]=true;
				break;
			}
		}
	}
	cout << res;
}