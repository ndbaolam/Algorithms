#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    s += "@";
    vector<int> res;
    int cnt = 0;
    for(char x : s){
        if(x == '1') ++cnt;
        else{
            res.push_back(cnt);
            cnt = 0;
        }
    }
    sort(begin(res), end(res), greater<int>());
    int ans = 0;
    for(int i = 0; i < res.size(); i += 2){
        ans += res[i];
    }
    cout << ans << endl;
}