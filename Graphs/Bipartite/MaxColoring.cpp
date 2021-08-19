//https://codeforces.com/contest/1328/problem/D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[200005];
ll vis[200005];
ll col[200005];

void dfs(int par) {
    vis[par] = 1;
    for (int child:gp[par]) {
        if (col[par] == col[child]) {
            col[child] = 3;
            continue;
        }
        if (!vis[child]) {
            if (col[par] == 1) {
                col[child] = 2;
            } else if (col[par] == 2) {
                col[child] = 1;
            } else {
                col[child] = 1;
            }
            dfs(child);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt, n, a, b;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; i++)gp[i].clear(), vis[i] = 0, col[i] = -1;

        int a[n + 1];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i + 1]) {
                gp[i].push_back(i + 1), gp[i + 1].push_back(i);
            }
        }
        if (a[1] != a[n]) {
            gp[1].push_back(n), gp[n].push_back(1);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                col[i] = 1;
                dfs(i);
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, (int) col[i]);
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; ++i) {
            cout << col[i] << " ";
        }
        cout << "\n";
    }
}
