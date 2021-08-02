//https://www.spoj.com/problems/SUBMERGE/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<ll> gp[1000001];
ll vis[1000001];
ll timer;
ll in[1000001];
ll LCA[1000001];
set<int> AP;

void dfs(int node, int root) {
    vis[node] = 1;
    LCA[node] = in[node] = timer++;
    int Children = 0;
    for (int child:gp[node]) {
        if (child == root)continue;
        if (vis[child]) {
            LCA[node] = min(LCA[node], in[child]);
        } else {
            dfs(child, node);
            Children++;
            LCA[node] = min(LCA[node], LCA[child]);
            if (in[node] <= LCA[child] && root != -1) {
                AP.insert(node);
            }
        }
        if (root == -1 && Children > 1)AP.insert(node);
    }
}

signed main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    ll n, m, a, b;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 1; i <= n; ++i) {
            vis[i] = 0;
            gp[i].clear();
        }
        AP.clear();
        while (m--) {
            cin >> a >> b;
            gp[a].push_back(b), gp[b].push_back(a);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, -1);
            }
        }
        cout << AP.size() << "\n";
    }
}
