#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    map<char,int> mp;
    for(int i=0;i<n;i++)
    {
        char x; cin >> x;
        mp[x]++;
    }
    
    cout << (*mp.begin()).first    << " " << (*mp.begin()).second << endl;
    cout<<endl;
    cout << (*mp.rbegin()).first    << " " << (*mp.rbegin()).second << endl;
    cout << endl;
    for(auto x :mp)    
        cout << x.first << " " << x.second << endl;;
    cout << endl;

    for(auto it = mp.rbegin();it!=mp.rend();it++)
            cout << (*it).first << " " << (*it).second << endl;
}    