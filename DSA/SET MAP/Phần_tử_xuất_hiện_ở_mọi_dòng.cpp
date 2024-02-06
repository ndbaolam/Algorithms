#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    int a[N][N];
    map<int,int> m;
    for(int i = 0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> a[i][j];

    for(int i=0;i<N;i++)
        m[a[0][i]]=1;

    for(int i = 1;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(m[a[i][j]]==i)
                m[a[i][j]]++;
        }
    }
    bool check = false;
    for(auto x : m)
    {
        if(x.second==N)
        {
            check = true;
            cout << x.first << " ";
        }
    }
    if(check==false)
        cout << "NOT FOUND";
}