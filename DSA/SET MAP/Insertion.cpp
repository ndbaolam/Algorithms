#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    int a[N], b[M];
    set<int> setB;
    for(int& x : a) 
        cin >> x;
    for(int& x : b) 
    {
        cin >> x;
        setB.insert(x);
    }
    for(int x: a)
    {
        if(setB.count(x))
        {
            cout << x << " ";
            setB.erase(x);
        }
    }
}    