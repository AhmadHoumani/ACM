//https://codeforces.com/contest/24/problem/A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<pair<int, int>> gp[100001];
int n, direction, cnt, sum;

void dfs(int u, int p = -1) {
    ++cnt;
    for (auto e: gp[u]) {
        int v = e.first;
        int c = e.second;
        if (cnt == n + 1)
            return;
        if (v != p) {
            direction += c;
            dfs(v, u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        sum += c;
        gp[u].push_back({v, c});
        gp[v].push_back({u, 0});
    }
    dfs(1);

    cout << min(direction, sum - direction);

}



