#include <bits/stdc++.h>
using namespace std;

string lower(string str)
{
    for(char &c : str)
        c=tolower(c);
    return str;
}

string upper(string str)
{
    for(char &c : str)
        c=toupper(c);
    return str;
}
int main()
{
    string name;
    getline(cin,name);
    stringstream S(name);
    string tmp;
    vector<string> v;
    while(S>>tmp)
        v.push_back(tmp);
    for(auto &i : v)
    {
        if(i!=*v.rbegin())
        {
            i=lower(i);
            *(i.begin())=toupper(*(i.begin()));
        }
        else i = upper(i);
    }

    for(auto i = 0; i < v.size()-2;i++ )
        cout << v[i] << " ";
    cout << v[v.size()-2] <<", "<< v[v.size()-1] << endl;

    cout << *v.rbegin() << ", ";
    for(auto i : v)
        if(i!=*v.rbegin())
            cout << i << " ";
}