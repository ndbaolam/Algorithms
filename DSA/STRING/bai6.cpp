#include <bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin >> str;
    for(char &c : str)
        c = tolower(c);
    set<char> check;
    for(char i = 'a';i<='z';i++)
        check.insert(i);
    for(auto c : check)
    {
        if(str.find(c)== string::npos)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}