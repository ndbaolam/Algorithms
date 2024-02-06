#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isvowel(char c){
    return c == 'A' || c == 'E';
}

bool check(string s){
    for(int i = 1; i < s.size() - 1; i++){
        if(isvowel(s[i]) && !isvowel(s[i - 1]) && !isvowel(s[i + 1]))
            return false;
    }
    return true;
}

int main(){
    char c; cin >> c;
    string s = "";
    for(char i = 'A'; i <= c; i++){
        s += i;
    }
    do{
        if(check(s)){
            cout << s << endl;
        }
    }while(next_permutation(s.begin(), s.end()));
}