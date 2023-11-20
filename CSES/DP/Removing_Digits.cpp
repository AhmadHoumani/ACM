#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
    io;
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num > 0) {
            int digit = num % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
            num /= 10;
        }
    }
    cout << dp[n];
}




