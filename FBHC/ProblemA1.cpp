https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1\
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;

signed main() {
    freopen("fuel.in", "r", stdin);
    ll tt, k, a, b;
    cin >> tt;
    while (tt--) {
        cin >> k >> a >> b;
        if (a == b || (a > k && b > k)) {
            cout << 0 << "\n";
        } else if (a + b == k) {
            cout << abs(a - b);
        } else {
            lld mn = min(a, b);
            ll rest = k - mn;
            cout << rest - mn;
        }
    }
}








v
