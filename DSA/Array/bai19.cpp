#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n; cin >> n;
	int a[n];
	for(int &i : a)
		cin >> i;

	int ans = 1;
    int idx = 1;
    int cur = 1;
    ll sum_cur = 0, sum_ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            ++cur;
            sum_cur += a[i];
        }
        else {
            cur = 1;
            sum_cur = a[i];
        }
        if (cur >= ans) {
            if (cur == ans) {
                if (sum_cur > sum_ans)
                    idx = i;
            }
            ans = cur;
            idx = i;
        }
    }
    cout << ans << "\n";
    for (int i = idx - ans + 1; i <= idx; ++i)
        cout << a[i] << " ";
}