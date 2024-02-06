#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    return a.size() > b.size();
}
int main()
{
   string str; getline(cin,str);
   stringstream ss(str);
   string tmp1, tmp2;
   set<string> se;
   while(ss >> tmp1)
        se.insert(tmp1);
    for(auto i : se)
        cout << i << " ";
    cout << endl;

    vector<string> v;
    for(auto i : se)
        v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    for(auto i : v)
        cout << i << " ";
}