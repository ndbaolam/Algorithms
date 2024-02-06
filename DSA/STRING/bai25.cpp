#include <bits/stdc++.h>
using namespace std;

string minimum_number(int m, int s) {
    if (s > m * 9 || (m > 1 && s == 0)) return "x";
    
    string a(m, '0');
    a[0] = '1', s -= 1;
    for (int i = m - 1; i > 0; --i) {
        if (s >= 9) a[i] = '9', s -= 9;
        else a[i] = s + '0', s = 0;
    }
    a[0] += s;
    return a;
}

string maximum_number(int m, int s) {
    if (s > m * 9 || (m > 1 && s == 0)) return "x";
    
    string a(m, '0');
    a[0] = '9', s -= 9;
    for (int i = 1; i < m ; ++i) {
        if (s >= 9) a[i] = '9', s -= 9;
        else a[i] = s + '0', s = 0;
    }
    a[m-1] += s;
    return a;
}
int main()
{
	int m, s;
	cin >> m >> s;
	if(minimum_number(m,s) == "x"|| maximum_number(m,s) == "x")
		cout << "NOT FOUND";
	else
		cout <<minimum_number(m,s) << " " << maximum_number(m,s);
}