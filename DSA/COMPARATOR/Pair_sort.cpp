#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int d(pair<int,int> p1)
{
    return pow(p1.first,2)+pow(p1.second,2);
}

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    if(d(p1) != d(p2))
        return d(p1) < d(p2);
    else
    {
        if(p1.first!=p2.first)
            return p1.first < p2.first;
        else
            return p1.second < p2.second;
    }
}

int main()
{
    int N; cin >> N;
    pair<int,int> p[N];
    for(int i=0;i<N;i++)
        cin >> p[i].first >> p[i].second;

    sort(p,p+N,cmp);
    for(auto i : p)
        cout << i.first << " " << i.second << endl;
}