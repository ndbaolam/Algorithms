#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	int cnt=0;

	for(int i=0;i<n-1;i++)
	{
		int mini = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[mini] < a[j])
			{
				mini=j;
			}
		}
		//if(mini!=i)
		{
			++cnt;
			swap(a[mini],a[i]);
			cout << "Buoc " << cnt << ": ";
			for(int k : a) cout << k << " ";
			cout << endl;
		}
	}
}