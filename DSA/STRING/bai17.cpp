#include <bits/stdc++.h>
using namespace std;

string strlwr(string str)
{
    for(auto &i : str)
        i=tolower(i);    
    return str;
}
int main()
{
    string str, t;
    getline(cin, str);
    str = strlwr(str);
    vector<string> v;

    stringstream S(str);
    while(S >>t)
        v.push_back(t);

    for(auto &i : v)
        i[0] = toupper(i[0]);
    for(auto &i : *(v.rbegin()))
        i=toupper(i);

    for(int i = 0; i < v.size() - 2; i++)
        cout << v[i] << " ";
    cout << v[v.size()-2] << ", " << v[v.size()-1] << endl;

    cout << v[v.size()-1] << ", ";
    for(int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " ";
}    