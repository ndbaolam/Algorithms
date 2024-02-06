#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, x;
	cin >> n >> x;
	int a[n];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
 
    sort(a + 1, a + 1 + n);
    for (int i = 3; i <= n; i++) {
        int j = 1, k = i - 1;
 
        while (j < k) {
            if (a[i] + a[j] + a[k] == x) {
                cout << "YES\n";
                return 0;
            }
            else if (a[i] + a[j] + a[k] > x) --k;
            else j++;
        }
    }
    cout << "NO\n";
	return 0;
}