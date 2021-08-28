#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;

signed main() {

    int tt, n;
    cin >> tt;
    while (tt--) {
        cin >> n;
        char a[n][n];
        int row[n];
        int col[n];
        fill(row, row + n, n);
        fill(col, col + n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 'O') {
                    row[i] = n + 1;
                    continue;
                } else if (a[i][j] == 'X') {
                    row[i]--;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[j][i] == 'O') {
                    col[i] = n + 1;
                    continue;
                } else if (a[j][i] == 'X') {
                    col[i]--;
                }
            }
        }
        ll mnr = n + 1;
        ll mnc = n + 1;

        for (int i = 0; i < n; i++) {
            if (row[i] < mnr) {
                mnr = row[i];
            }
            if (col[i] < mnc) {
                mnc = col[i];
            }
        }
        ll r = 0;
        ll c = 0;
        for (int i = 0; i < n; ++i) {
            if (row[i] == mnr) {
                r++;
            }
            if (col[i] == mnc) {
                c++;
            }
        }
        if (mnc == mnr) {
            cout << mnr << " " << c + r << "\n";
        } else if (mnc > mnr) {
            cout << mnr << " " << r << "\n";
        } else {
            cout << mnc << " " << c << "\n";
        }
    }
}








