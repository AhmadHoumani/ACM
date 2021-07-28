//https://codeforces.com/contest/687/problem/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<ll> gp[100005];
ll vis[100005];
ll col[100005];
vector<ll> res[2];
bool isC = 1;

void dfs(ll node, bool c) {
    vis[node] = 1;
    col[node] = c;
    res[c].push_back(node);
    for (ll child:gp[node]) {
        if (!vis[child]) {
            dfs(child, c ^ 1);
        } else {
            if (col[child] == col[node]) {
                isC = 0;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        gp[a].push_back(b), gp[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    if (isC) {
        for (int i = 0; i < 2; ++i) {
            cout << res[i].size() << "\n";
            for (auto child:res[i]) {
                cout << child << " ";
            }
            cout << "\n";
        }
    } else {
        cout << -1;
    }
}
