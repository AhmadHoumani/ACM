#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<pair<int, int>> gp[1000001];
int vis[1000001];
ll leafsum = 0;
int cost[51];
vector<int> maxs;
int inde = 1;

void dfs(ll root, ll sum) {
    vis[root] = 1;
    for (auto child: gp[root]) {
        if (!vis[child.first]) {
            dfs(child.first, sum + child.second);
        } else if (gp[root].size() == 1) {
            if (sum > leafsum) {
                leafsum = sum;
                inde = root;
                //cout << leafsum << "\n";

            }
        }
    }
}

signed main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    ll tt, n, a, b, c;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> cost[i];
        }
        n--;
        for (int i = 1; i <= n; ++i) {
            cin >> a >> b;
            gp[a].push_back({b, cost[b]}), gp[b].push_back({a, cost[a]});
        }
        //dfs(1, 0);
        for (auto x: gp[7]) {
            cout << x.first << " ";
        }
    }
}


