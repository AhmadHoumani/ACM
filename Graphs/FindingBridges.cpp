//https://codeforces.com/contest/118/problem/E
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
bool foundBridge;
vector<pair<int, int>> FEdges;

void dfs(int node, int root) {
    vis[node] = 1;
    LCA[node] = in[node] = timer++;
    for (int child:gp[node]) {
        if (child == root) {
            continue;
        }
        if (vis[child]) {
            LCA[node] = min(LCA[node], in[child]);
            if (in[node] > in[child]) {
                FEdges.push_back({node, child});
            }
        } else {
            dfs(child, node);
            if (LCA[child] > in[node]) {
                foundBridge = true;
                return;
            }
            FEdges.push_back({node, child});
            LCA[node] = min(LCA[node], LCA[child]);
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
    dfs(1, -1);
    if (foundBridge) {
        cout << 0;
    } else {
        for (auto e:FEdges) {
            cout << e.first << " " << e.second << "\n";
        }
    }
}
