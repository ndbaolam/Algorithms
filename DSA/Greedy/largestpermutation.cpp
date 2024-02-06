#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

void solve2(int a[], int n, int k)
{
	priority_queue<pair<int,int>> q;
	for(int i=0;i<n;i++) q.push({a[i],i});
	for(int i=0;i<n;i++)
	{
		auto [x,y] = q.top();
		q.pop();

		if(a[i]<x)
		{
			q.push({a[i],y});
			swap(a[i],a[y]);			
			if(--k<=0) break;
		}
	}
}

void solve1(int a[], int n, int k)
{
	set<pair<int, int>, greater<pair<int, int>>> s;
    for (int i = 0; i < n; i++) s.insert({a[i], i});

    for (int i = 0; i < n; i++) {
        auto it = *(s.begin());
        s.erase(s.begin());

        if (a[i] < it.first) {
            s.erase({a[i], i});
            s.insert({a[i],it.second});
            swap(a[i], a[it.second]);
            if (--k <= 0) break;
        }
    }
}

int main()
{
	int n, k; cin >> n >> k;
	int a[n];
	for(int &i : a) cin >> i;
	if(k>=n) sort(a,a+n,greater<int>());
	else solve1(a,n,k);
	for(int i : a)
		cout << i << " ";
}
// 1 2 3 4 -- 1 2 3 4
// 4 2 3 1
// 