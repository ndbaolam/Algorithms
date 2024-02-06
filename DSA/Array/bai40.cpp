#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m; cin >> n >> m;
    int a[n];
    int b[m];
    set<pair<int,int>> s;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
        cin >> b[i];

    int pos=0;
    for(int x :a)
    {
        if(x==b[pos]) ++pos;
        if(pos==m)
        {
            cout <<"YES";
            return 0;
        }
    }
    cout << "NO";
}