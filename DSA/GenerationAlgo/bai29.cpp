#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
bool final = false;
string s;

void ktao(){
    s = string(n, '(');
}

void sinh(){
    int i = n - 1;
    while(i >= 0 && s[i] == ')'){
        s[i] = '(';
        --i;
    }
    if(i == -1){
        final = true;
    }
    else s[i] = ')';
}

bool check(string s){
    stack<char> st;
    for(char x : s){
        if(x == '(')
            st.push(x);
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    cin >> n;
    if(n % 2 == 1){
        cout << "NOT FOUND\n";
        return 0;
    }
    ktao();
    while(!final){
        if(check(s)){
            cout << s << endl;
        }
        sinh();
    }
}