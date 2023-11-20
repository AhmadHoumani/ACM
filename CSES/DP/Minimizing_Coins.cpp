#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    io;
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, 1e9);
    vector<int> arr(n);
    for (auto &num: arr)cin >> num;
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= arr[j]) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    cout << (dp[x] < 1e9 ? dp[x] : -1);
}




