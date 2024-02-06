#include <bits/stdc++.h>
using namespace std;

bool cmp1(pair<char,int> a, pair<char,int> b)
{
    if(a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
}
bool cmp2(pair<char,int> a, pair<char,int> b)
{
    if(a.second != b.second)
        return a.second < b.second;
    else return a.first > b.first;
}
int main()
{
    string str;
    getline(cin,str);
    map<char,int> mp;
    for(char c : str)
        mp[c]++;
    vector<pair<char,int>> c;
    for(auto i : mp)
        c.pop_back({i.first,i.second});

    sort(c.begin(),c.end(),cmp1);
    cout << c.begin()->first << " " << c.begin()->second << endl;
    sort(c.begin(),c.end(),cmp2);
    cout << c.begin()->first << " " << c.begin()->second << endl;
}