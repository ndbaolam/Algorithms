#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main() {
    string s; cin >> s;
    map<char, int> mp;
    int Max = 0;
    int l = 0;
    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        while (mp[s[i]] == 2) {
            mp[s[l]]--;
            l++;
        }
        Max = max(i - l + 1, Max);
    }
    cout << Max;
    return 0;
}