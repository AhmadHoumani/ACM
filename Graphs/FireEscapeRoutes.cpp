//https://www.codechef.com/problems/FIRESC
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[100005];
int vis[100005];
int Cnodes = 1;

void dfs(int node) {
    vis[node] = 1;
    Cnodes++;
    for (int child:gp[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            gp[i].clear(), vis[i] = 0;
        }
        while (m--) {
            cin >> a >> b, gp[a].push_back(b), gp[b].push_back(a);
        }
        ll count = 0;
        ll res = 1;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                Cnodes = 0;
                dfs(i);
                count++;
                res = (res * Cnodes) % MOD;
            }
        }
        cout << count << " " << res << "\n";
    }

}
