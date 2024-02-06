#include <bits/stdc++.h>
using namespace    std;

int X;

bool cmp1(int a, int b)
{
    int c = abs(a-X);
    int d = abs(b-X);
    if(c!=d)
        return c<d;
    else return a<b;
}

int main()
{
    int N; cin >> N >> X;
    vector<int> v,a,b;
    for(int i=0;i<N;i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end(),cmp1);
    for(int i:v)
        cout << i << " ";
    cout << endl;
    
    for(int i=0;i<N;i++)
    {
        if(v[i]%2==0)
            a.push_back(v[i]);
        else b.push_back(v[i]);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    for(int i : a)
        cout << i << " ";
    for(int i  : b)
        cout << i << " ";

}