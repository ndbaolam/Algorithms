#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

int main()
{
    string s; cin >> s;
    map<char,int> mp;
    for(char c : s)
        mp[c]++;
    priority_queue<int> q;
    for(auto i : mp)
        q.push(i.second);
    while(true)
    {
        int a=q.top(); q.pop();
        int b=q.top(); q.pop();
        if(b==0 && a>1) 
        {
            cout << "NO";
            return 0;
        }
        else if(b==0 && (a==0||a==1))
        {
            cout << "YES";
            return 0;
        }
        q.push(--a); q.push(--b);
    }
}