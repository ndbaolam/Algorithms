#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    set<int> s;
    int a[N];
    for(int &x : a)
        cin>>x;
    for(int i=0;i<N;i++)
    {
        if(s.find(a[i])==s.end())
        {
            cout << a[i] << " ";
            s.insert(a[i]);
        }
    }
}
