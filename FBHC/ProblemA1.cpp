#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
//"A", "E", "I", "O", and "U"
bool isV(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    string str;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        cin >> str;
        ll n = str.size();
        if (n == 1) {
            cout << "Case #" << i << ": " << 0 << "\n";
        } else {
            int vow[26];
            int con[26];
            ll cv = 0, cc = 0;
            memset(vow, 0, sizeof vow);
            memset(con, 0, sizeof con);
            for (int i = 0; i < n; ++i) {
                if (isV(str[i])) {
                    cv++;
                    vow[(ll) str[i] - 'A']++;
                    //cout << (ll) str[i] - 'A';
                } else {
                    cc++;
                    con[(ll) str[i] - 'A']++;

                }
            }
            ll index = 0, mx = 0, ans = 0;
            if (cc >= cv) {
                ans += cc;
                ans += cv * 2;
                for (int i = 0; i < 26; ++i) {
                    if (vow[i] > mx) {
                        mx = vow[i];
                        index = i;
                    }
                }
                ll done = vow[index];
                ans -= done * 2;
            } else {
                ans += cv;
                ans += cc * 2;
                for (int i = 0; i < 26; ++i) {
                    if (con[i] > mx) {
                        mx = con[i];
                        index = i;
                    }
                }
                ll done = con[index];
                ans -= done * 2;
            }
            cout << "Case #" << i << ": " << ans << "\n";
        }
    }
}








