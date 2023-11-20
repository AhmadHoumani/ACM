#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    io;
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i >= j) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n];
}




