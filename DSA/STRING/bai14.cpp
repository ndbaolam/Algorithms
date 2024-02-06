#include <bits/stdc++.h>
using namespace std;

bool cmp2(pair<string,int> a, pair<string,int> b)
{
    if(a.second != b.second)
        return a.second < b.second;
    else return a.first > b.first;
}
bool cmp1(pair<string,int> a, pair<string,int> b)
{
    if(a.second != b.second)
        return a.second > b.second;
    else return a.first > b.first;
}
int main()
{
    string S; getline(cin, S);
    stringstream ss(S);
    string tmp;

    map<string,int> map;
    while(ss >> tmp)
        map[tmp]++;

    vector<pair<string,int>> v;
    for(auto i : map)
        v.push_back(i);

sort(v.begin(), v.end(), cmp1);
    cout << v.begin()->first << " " << v.begin()->second << endl;

    sort(v.begin(), v.end(), cmp2);
    cout << v.begin()->first << " " << v.begin()->second << endl;
}