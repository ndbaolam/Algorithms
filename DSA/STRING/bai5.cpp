#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    getline(cin,a);
    getline(cin,b);
    set<char> s1, s2,s3;
    for(char c : a)
        s1.insert(c);
    for(char c: b)
        s2.insert(c);

    for(char c : s1)
    {
        if(!s2.count(c))
            cout << c;
    }
    cout << endl;
    for(char c : s2)
    {
        if(!s1.count(c))
            cout << c;
    }
}