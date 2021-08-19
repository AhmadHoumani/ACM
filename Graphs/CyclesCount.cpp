//https://codeforces.com/contest/977/problem/E
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[200005];
ll vis[200005];
bool isCycle;

void dfs(int par) {
    vis[par] = 1;
    if (gp[par].size() != 2) {
        isCycle = false;
    }
    for (int child:gp[par]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, a, b, ans = 0;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);
    }
    for (int i = 1; i < n; ++i) {
        isCycle = true;
        if (!vis[i]) {
            dfs(i);
            if (isCycle) {
                ans++;
            }
        }
    }
    cout << ans;
}
