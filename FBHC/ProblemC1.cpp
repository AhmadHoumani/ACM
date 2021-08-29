#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<int> gp[51];
int vis[51];
ll leafsum = 0;
int cost[51];
vector<int> maxs;
int inde = 1;

void dfsd(int node) {
    vis[node] = 1;
    for (int child:gp[node]) {
        if (!vis[child] && child != 1) {
            dfsd(child);
        }
    }
}

void dfs(ll root, ll sum) {
    vis[root] = 1;
    for (auto child: gp[root]) {
        if (!vis[child]) {
            dfs(child, sum + cost[child]);
        } else if (gp[root].size() == 1) {
            if (sum > leafsum) {
                leafsum = sum;
                inde = root;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt, n, a, b, c;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        leafsum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            gp[i].clear(), vis[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> cost[i];
        }
        n--;
        for (int i = 1; i <= n; ++i) {
            cin >> a >> b;
            gp[a].push_back(b), gp[b].push_back(a);
        }
        
        if (gp[1].size() == 1) {
            dfs(1, 0);
            cout << "Case #" << i << ": " << leafsum + cost[1] << "\n";
        } else {
            dfs(1, 0);
            ll fst = leafsum;
            memset(vis, 0, sizeof vis);
            dfsd(inde);
            leafsum = 0;
            dfs(1, 0);
            ll snd = leafsum;
            cout << "Case #" << i << ": " << fst + snd + cost[1] << "\n";
        }
    }

}








