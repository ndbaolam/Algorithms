#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
int cnt = 0;
void merge(int a[], int l, int m, int r)
{
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < x.size() && j < y.size())
	{
		if(x[i] < y[j]) a[l++] = x[i++];
		else a[l++] = y[j++];
	}
	while(i < x.size()) a[l++] = x[i++];
	while(j < y.size()) a[l++] = y[j++];
}

void mergeSort(int a[], int l, int r)
{
	++cnt;
	if(l >= r) return;
	int m = (l+r)/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a,l,m,r);
}

int main()
{
	int n = 100;
	int a[n];
	srand(time(NULL));
	for(int& x : a) x = rand() % 1000;
	cout << "Before MergeSort: \n";
	for(int x : a) cout << x << ' ';
	cout << endl;
	mergeSort(a,0,n-1);
	cout << "After MergeSort:\n";
	for(int x : a) cout << x << ' ';
		cout << "\nNumber of recursion being called: " << cnt << endl;
}