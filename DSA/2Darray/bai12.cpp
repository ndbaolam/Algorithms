#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    vector<int> v[n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		v[i].push_back(a[j][i]);
    	}
    }
    for(int i=0;i<n;i++)
    {
    	sort(v[i].begin(),v[i].end());
    }

    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout << v[j][i] << " ";
    	}
    	cout << endl;
    }
}