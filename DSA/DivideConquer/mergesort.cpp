#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int cnt;

void merge(vector<int>& a, int l, int m, int r)
{
	vector<int> x(a.begin()+l,a.begin()+m+1);
	vector<int> y(a.begin()+m+1,a.begin()+r+1);
	int i=0, j=0;
	while(i < x.size() && j < y.size())
	{
		if(x[i] <= y[i]) a[l++] = x[i++];
		else a[l++] = y[j++];
	}
	while(i < x.size()) a[l++] = x[i++];
	while(j < y.size()) a[l++] = y[j++];
}

void mergeSort(vector<int>& a, int l, int r)
{
	if(l >= r) return;
	int m = (l+r)/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a,l,m,r);
}

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	//for(int &x : a) cin >> x;
	srand(time(NULL));
	for(int &x : a) x = rand() % 1000;
	mergeSort(a,0,n-1);
	for(int &x : a) cout << x << ' ';
}

