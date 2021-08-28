//https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B
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
        int rows[n];
        fill(rows, rows + n, n);
        int col[n];
        fill(col, col + n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 'O') {
                    rows[j] = col[i] = n + 1;

                } else if (a[i][j] == 'X') {
                    rows[j]--, col[j]--;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        for (auto x: rows) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: col) {
            cout << x << " ";
        }
    }
}








