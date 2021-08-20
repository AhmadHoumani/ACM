//https://codeforces.com/problemset/problem/1419/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll p, q, j, k, n, d, l, m, t, h, i;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a[n];
        d = 0;
        k = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            d += (a[i] - m);
            if (a[i] == m)
                k++;

        }
        if (k == n)
            cout << 0 << "\n";
        else if (k > 0 || d == 0)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
}


