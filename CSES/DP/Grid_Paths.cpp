#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 1000;
ll dp[N][N];


int main() {
    io;
    int n;
    cin >> n;
    char arr[n][n];
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (i == 0 and arr[i][j] != '*' and j > 0 and dp[i][j - 1] > 0)dp[i][j] = 1;
            if (j == 0 and arr[i][j] != '*' and i > 0 and dp[i - 1][j] > 0)dp[i][j] = 1;
        }
    }
    if (arr[0][0] == '*') {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (arr[i][j] == '*')continue;
            dp[i][j] = (1ll * dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }


    cout << (dp[n - 1][n - 1]) % MOD;
}

