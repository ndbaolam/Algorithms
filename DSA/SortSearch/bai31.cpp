#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first!=b.first)   
         return a.first < b.first;
    else 
        return a.second < b.second;
}

int main()
{
    ll s, n; cin >> s >> n;
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++)
    {
        int a, b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        if(s>v[i].first)
            s+=v[i].second;
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}