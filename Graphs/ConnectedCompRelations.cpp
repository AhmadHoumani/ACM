//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
const lld pi = 3.14159265358979323846;
const ll MOD = 1000000007;
vector<ll> gp[1000001];
ll vis[1000001];
ll cntlist[1000001];
int cnt_comp;

void dfs(int node) {
    vis[node] = 1;
    cntlist[node] = cnt_comp;
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
    int t, n, k, a, b;

    string op;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> pp;
        cnt_comp = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            gp[i].clear(), vis[i] = 0;
        }
        while (k--) {
            cin >> a >> op >> b;
            if (op == "=") {
                gp[a].push_back(b), gp[b].push_back(a);
            } else {
                pp.push_back(make_pair(a, b));
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                cnt_comp++;
                dfs(i);
            }
        }
        bool hap = true;
        for (int i = 0; i < pp.size(); ++i) {
            if (cntlist[pp[i].first] == cntlist[pp[i].second]) {
                hap = false;
                break;
            }
        }
        if (hap) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
