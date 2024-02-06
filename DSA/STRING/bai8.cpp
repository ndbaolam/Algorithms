#include <bits/stdc++.h>
using namespace std;

int countWords(string str)
{
    stringstream ss(str);
    string tmp;
    int count = 0;
    while(ss >> tmp)
        count++;
    return count;
}
int main()
{
    string str; getline(cin,str);
    cout << countWords(str);
}