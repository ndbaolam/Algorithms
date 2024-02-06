#include <bits/stdc++.h>
using namespace std;

vector<string> temp;

bool cmp(string a, string b)
{
    if(a.size()!=b.size())
        return a.size() < b.size();
    else
        return find(temp.begin(),temp.end(),a) - temp.begin() < find(temp.begin(),temp.end(),b) - temp.begin();
}
bool check(string str)
{
    for(int i = 0;i<str.size();i++)
    {
        if(str[i]!=str[str.size()-i-1])
            return false;
    }
    return true;
}
int main()
{
    string S; getline(cin, S);
    stringstream ss(S);
    string tmp;
    multiset<string> se;

    while(ss >> tmp)
    {
        if(check(tmp))
        {
            temp.push_back(tmp);
            se.insert(tmp);
        }
    }
    
    vector<string> v;
    for(auto i : se)
        v.push_back(i);

    sort(v.begin(),v.end(),cmp);
    for(auto i : v)
        cout << i << " ";
}