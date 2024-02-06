#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    int a[n];
    multiset<int> s1,s2;
    for(int &i : a) 
    {
        cin >> i;
        if(i&1) s1.insert(i);
        else s2.insert(i);
    }

    if(n&1)
    {
        cout << "NO";
        return 0;
    }

    if(s1.size()&1 && s2.size()&1)
    {
        for(int x : s1)
        {
            if(s2.count(x-1) || s2.count(x+1))
            {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    else cout << "YES";
    //9 15 29
    //2 8 16
}